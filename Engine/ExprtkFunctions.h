/* ***** BEGIN LICENSE BLOCK *****
 * This file is part of Natron <http://www.natron.fr/>,
 * Copyright (C) 2013-2017 INRIA and Alexandre Gauthier-Foichat
 *
 * Natron is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Natron is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Natron.  If not, see <http://www.gnu.org/licenses/gpl-2.0.html>
 * ***** END LICENSE BLOCK ***** */

#ifndef NATRON_ENGINE_EXPRTKFUNCTIONS_H
#define NATRON_ENGINE_EXPRTKFUNCTIONS_H

// ***** BEGIN PYTHON BLOCK *****
// from <https://docs.python.org/3/c-api/intro.html#include-files>:
// "Since Python may define some pre-processor definitions which affect the standard headers on some systems, you must include Python.h before any standard headers are included."
#include <Python.h>
// ***** END PYTHON BLOCK *****

#include <string>

#include "Engine/TimeValue.h"
#include "Engine/ViewIdx.h"
#include "Engine/EngineFwd.h"


NATRON_NAMESPACE_ENTER;

EXPRTK_FUNCTIONS_NAMESPACE_ENTER;

typedef double exprtk_scalar_t;
typedef exprtk::symbol_table<EXPRTK_FUNCTIONS_NAMESPACE::exprtk_scalar_t> symbol_table_t;
typedef exprtk::expression<EXPRTK_FUNCTIONS_NAMESPACE::exprtk_scalar_t> expression_t;
typedef exprtk::results_context<EXPRTK_FUNCTIONS_NAMESPACE::exprtk_scalar_t> results_context_t;
typedef exprtk::parser<EXPRTK_FUNCTIONS_NAMESPACE::exprtk_scalar_t> parser_t;
typedef exprtk::igeneric_function<EXPRTK_FUNCTIONS_NAMESPACE::exprtk_scalar_t> generic_func_t;
typedef exprtk::ivararg_function<EXPRTK_FUNCTIONS_NAMESPACE::exprtk_scalar_t> vararg_func_t;
typedef exprtk::ifunction<EXPRTK_FUNCTIONS_NAMESPACE::exprtk_scalar_t> func_t;

typedef boost::shared_ptr<generic_func_t> generic_func_ptr;
typedef boost::shared_ptr<vararg_func_t> vararg_func_ptr;
typedef boost::shared_ptr<func_t> func_ptr;


void addVarargFunctions(TimeValue time, std::vector<std::pair<std::string, vararg_func_ptr > >* functions);
void addFunctions(TimeValue time, std::vector<std::pair<std::string, func_ptr > >* functions);
void addGenericFunctions(TimeValue time, std::vector<std::pair<std::string, generic_func_ptr > >* functions);

// Some functions (random) hold an internal state. Instead of using the same state for all threads,
// We create a copy of the function update in this symbol table
void makeLocalCopyOfStateFunctions(TimeValue time, symbol_table_t& symbol_table, std::vector<std::pair<std::string, func_ptr > >* functions);


EXPRTK_FUNCTIONS_NAMESPACE_EXIT;

NATRON_NAMESPACE_EXIT;


#endif // NATRON_ENGINE_EXPRTKFUNCTIONS_H
