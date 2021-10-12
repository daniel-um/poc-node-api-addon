#include <addon.h>

napi_value TimesTwo(napi_env env, napi_callback_info info) {
    napi_status status;
    size_t argc = 1;
    int number = 0;
    napi_value argv[1];
    status = napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    
    if (status != napi_ok) {
        napi_throw_error(env, NULL, "Failed to parse arguments");
    }
    
    status = napi_get_value_int32(env, argv[0], &number);
    
    if (status != napi_ok) {
        napi_throw_error(env, NULL, "Invalid number was passed as argument");
    }
    napi_value myNumber;
    number = number * 2;
    status = napi_create_int32(env, number, &myNumber);
    
    if (status != napi_ok) {
        napi_throw_error(env, NULL, "Unable to create return value");
    }
    
    return myNumber;   
}

napi_value ReturnObject(napi_env env, napi_callback_info info) {
    napi_status status = napi_generic_failure;

    // const obj = {}
    napi_value obj, value;
    status = napi_create_object(env, &obj);
    if (status != napi_ok) {
        napi_throw_error(env, NULL, "Unable to create object");
    }

    // Create a napi_value for 123
    status = napi_create_int32(env, 123, &value);
    if (status != napi_ok) {
        napi_throw_error(env, NULL, "Unable to create integer");
    }

    // obj.myProp = 123
    status = napi_set_named_property(env, obj, "myProp", value);
    if (status != napi_ok) {
        napi_throw_error(env, NULL, "Unable to set named property");
    }

    return obj;
}

napi_value ReturnArray(napi_env env, napi_callback_info info) {
    napi_status status = napi_generic_failure;

    // const arr = [];
    napi_value arr, value;
    status = napi_create_array(env, &arr);
    if (status != napi_ok) {
        napi_throw_error(env, NULL, "Unable to create array");
    }

    // Create a napi_value for 'hello'
    status = napi_create_string_utf8(env, "hello", NAPI_AUTO_LENGTH, &value);
    if (status != napi_ok) {
        napi_throw_error(env, NULL, "Unable to create string");
    }

    // arr[123] = 'hello';
    status = napi_set_element(env, arr, 123, value);
    if (status != napi_ok) {
        napi_throw_error(env, NULL, "Unable to set element");
    }

    return arr;
}

napi_value Init(napi_env env, napi_value exports) {
    napi_status status;
    napi_value fn;

    status = napi_create_function(env, NULL, 0, TimesTwo, NULL, &fn);
    if (status != napi_ok) {
        napi_throw_error(env, NULL, "Unable to wrap native function");
    }

    status = napi_set_named_property(env, exports, "timesTwo", fn);
    if (status != napi_ok) {
        napi_throw_error(env, NULL, "Unable to populate exports");
    }

    status = napi_create_function(env, NULL, 0, ReturnObject, NULL, &fn);
    if (status != napi_ok) {
        napi_throw_error(env, NULL, "Unable to wrap native function");
    }

    status = napi_set_named_property(env, exports, "returnObject", fn);
    if (status != napi_ok) {
        napi_throw_error(env, NULL, "Unable to populate exports");
    }

    status = napi_create_function(env, NULL, 0, ReturnArray, NULL, &fn);
    if (status != napi_ok) {
        napi_throw_error(env, NULL, "Unable to wrap native function");
    }

    status = napi_set_named_property(env, exports, "returnArray", fn);
    if (status != napi_ok) {
        napi_throw_error(env, NULL, "Unable to populate exports");
    }
    
    return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)