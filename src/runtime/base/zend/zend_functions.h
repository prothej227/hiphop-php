/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010- Facebook, Inc. (http://www.facebook.com)         |
   | Copyright (c) 1998-2010 Zend Technologies Ltd. (http://www.zend.com) |
   +----------------------------------------------------------------------+
   | This source file is subject to version 2.00 of the Zend license,     |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.zend.com/license/2_00.txt.                                |
   | If you did not receive a copy of the Zend license and are unable to  |
   | obtain it through the world-wide-web, please send a note to          |
   | license@zend.com so we can mail you a copy immediately.              |
   +----------------------------------------------------------------------+
*/

#ifndef __HPHP_ZEND_FUNCTIONS_H__
#define __HPHP_ZEND_FUNCTIONS_H__

#include <runtime/base/types.h>
#include <util/hash.h>

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////
// zend logic: These are not string utilities, but zend's special language
// semantics.

/**
 * Testing whether a string is numeric or not.
 */
DataType is_numeric_string(const char *str, int length, int64 *lval,
                           double *dval, int allow_errors = 0);

/**
 * Zend's way of incrementing a string. Definitely something we want to get rid
 * of in the future.
 */
char *increment_string(char *s, int &len);

/**
 * Whether or not a string is a valid variable name.
 */
bool is_valid_var_name(const char *var_name, int len);

///////////////////////////////////////////////////////////////////////////////

/**
 * Adapted from ap_php_conv_10 for fast signed integer to string conversion.
 */
char *
conv_10(register int64 num, register int *is_negative, char *buf_end,
        register int *len);

///////////////////////////////////////////////////////////////////////////////
}

#endif // __HPHP_ZEND_FUNCTIONS_H__
