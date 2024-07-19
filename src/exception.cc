#include "exception.h"
#include <zend_exceptions.h>

zend_class_entry *exception_ce;

void init_exception(INIT_FUNC_ARGS)
{
    zend_class_entry ce;
    INIT_NS_CLASS_ENTRY(ce, "Mapnik", "Exception", NULL);
    exception_ce = zend_register_internal_class_ex(
        &ce,
        (zend_class_entry*) zend_exception_get_default()
    );
}

void throw_mapnik_exception_with_message(const char *message, int code)
{
    zend_throw_exception(exception_ce, message, code);
}

zend_function_entry mapnik_functions[] = {
    PHP_FE_END
};