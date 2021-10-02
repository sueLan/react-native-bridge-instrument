//
//  CxxNativeModulePerfLogger.cpp
//  RNTester
//
//  Created by Zheng Rongyan on 7/1/21.
//  Copyright © 2021 Facebook. All rights reserved.
//

#include "CxxNativeModulePerfLogger.h"
 

namespace facebook {
namespace react {

#define function_name(var) #var

CxxNativeModulePerfLogger::CxxNativeModulePerfLogger() {
  module_os_logger = os_log_create("com.ry.signpost.logger", "module");
  js_require_os_logger = os_log_create("com.ry.signpost.logger", "js_require");
  sync_method_call_logger = os_log_create("com.ry.signpost.logger", "sync_method_call");
  async_method_call_logger = os_log_create("com.ry.signpost.logger", "async_method_call");
  points_of_interest_logger = os_log_create("com.ry.signpost.logger", OS_LOG_CATEGORY_POINTS_OF_INTEREST);
}

void CxxNativeModulePerfLogger::moduleDataCreateStart(const char *moduleName, int32_t id) {
  os_signpost_interval_begin(module_os_logger, id, function_name(__func__), " %s", moduleName);
};

void CxxNativeModulePerfLogger::moduleDataCreateEnd(const char *moduleName, int32_t id) {
  os_signpost_interval_end(module_os_logger, id, function_name(__func__), "%s", moduleName);
};

void CxxNativeModulePerfLogger::moduleCreateStart(const char *moduleName, int32_t id) {
  os_signpost_interval_begin(module_os_logger, id, function_name(__func__), "%s", moduleName);
};

void CxxNativeModulePerfLogger::moduleCreateCacheHit(const char *moduleName, int32_t id) {
  os_signpost_event_emit(module_os_logger, id, function_name(__func__), "%s", moduleName);
};

void CxxNativeModulePerfLogger::moduleCreateConstructStart(
                                                           const char *moduleName,
                                                           int32_t id) {
  os_signpost_interval_begin(module_os_logger, id, function_name(__func__), "%s", moduleName);
};

void CxxNativeModulePerfLogger::moduleCreateConstructEnd(
                                                           const char *moduleName,
                                                           int32_t id) {
  os_signpost_interval_end(module_os_logger, id, function_name(__func__), "%s", moduleName);
};

void CxxNativeModulePerfLogger::moduleCreateSetUpStart(
                                                           const char *moduleName,
                                                           int32_t id) {
  os_signpost_interval_begin(module_os_logger, id, function_name(__func__), "%s", moduleName);
};


void CxxNativeModulePerfLogger::moduleCreateSetUpEnd(
                                                           const char *moduleName,
                                                           int32_t id) {
  os_signpost_interval_end(module_os_logger, id, function_name(__func__), "%s", moduleName);
};

void CxxNativeModulePerfLogger::moduleCreateEnd(
                                                           const char *moduleName,
                                                           int32_t id) {
  os_signpost_interval_end(module_os_logger, id, function_name(__func__), "%s", moduleName);
};

void CxxNativeModulePerfLogger::moduleCreateFail(
                                                           const char *moduleName,
                                                           int32_t id) {
  os_signpost_event_emit(module_os_logger, id, function_name(__func__), "%s", moduleName);
};

void CxxNativeModulePerfLogger::moduleJSRequireBeginningStart(const char *moduleName) {
  os_signpost_interval_begin(js_require_os_logger, OS_SIGNPOST_ID_EXCLUSIVE,  function_name(__func__), "%s", moduleName);
};

void CxxNativeModulePerfLogger::moduleJSRequireBeginningCacheHit(const char *moduleName) {
  os_signpost_event_emit(js_require_os_logger, OS_SIGNPOST_ID_EXCLUSIVE, function_name(__func__), "%s", moduleName);
};

void CxxNativeModulePerfLogger::moduleJSRequireBeginningEnd(const char *moduleName) {
  os_signpost_interval_end(js_require_os_logger, OS_SIGNPOST_ID_EXCLUSIVE, function_name(__func__), "%s", moduleName);
};

void CxxNativeModulePerfLogger::moduleJSRequireBeginningFail(const char *moduleName) {
  os_signpost_event_emit(js_require_os_logger, OS_SIGNPOST_ID_EXCLUSIVE, function_name(__func__), "%s", moduleName);
};

void CxxNativeModulePerfLogger::moduleJSRequireEndingStart(const char *moduleName) {
  os_signpost_interval_begin(js_require_os_logger, OS_SIGNPOST_ID_EXCLUSIVE, function_name(__func__), "%s", moduleName);
};

void CxxNativeModulePerfLogger::moduleJSRequireEndingEnd(const char *moduleName) {
  os_signpost_interval_end(js_require_os_logger, OS_SIGNPOST_ID_EXCLUSIVE, function_name(__func__), "%s", moduleName);
};

void CxxNativeModulePerfLogger::moduleJSRequireEndingFail(const char *moduleName) {
  os_signpost_event_emit(js_require_os_logger, OS_SIGNPOST_ID_EXCLUSIVE, function_name(__func__), "%s", moduleName);
};

void CxxNativeModulePerfLogger::syncMethodCallStart(
                                                    const char *moduleName,
                                                    const char *methodName) {
  os_signpost_interval_begin(sync_method_call_logger, OS_SIGNPOST_ID_EXCLUSIVE, function_name(__func__), "%s %s", moduleName, methodName);
  os_signpost_event_emit(points_of_interest_logger, OS_SIGNPOST_ID_EXCLUSIVE, function_name(__func__), "%s %s", moduleName, methodName);

};

void CxxNativeModulePerfLogger::syncMethodCallArgConversionStart(
                                                    const char *moduleName,
                                                    const char *methodName) {
  os_signpost_interval_begin(sync_method_call_logger, OS_SIGNPOST_ID_EXCLUSIVE, function_name(__func__), "%s %s",  moduleName, methodName);
};

void CxxNativeModulePerfLogger::syncMethodCallArgConversionEnd(
                                                               const char *moduleName,
                                                               const char *methodName) {
  os_signpost_interval_end(sync_method_call_logger, OS_SIGNPOST_ID_EXCLUSIVE, function_name(__func__), "%s %s", moduleName, methodName);
};

void CxxNativeModulePerfLogger::syncMethodCallExecutionStart(
                                                    const char *moduleName,
                                                    const char *methodName) {
  os_signpost_interval_begin(sync_method_call_logger, OS_SIGNPOST_ID_EXCLUSIVE, function_name(__func__), "%s %s", moduleName, methodName);
};

void CxxNativeModulePerfLogger::syncMethodCallExecutionEnd(
                                                    const char *moduleName,
                                                    const char *methodName) {
  os_signpost_interval_end(sync_method_call_logger, OS_SIGNPOST_ID_EXCLUSIVE, function_name(__func__), "%s %s", moduleName, methodName);
};
 
void CxxNativeModulePerfLogger::syncMethodCallReturnConversionStart(
                                                    const char *moduleName,
                                                    const char *methodName) {
  os_signpost_interval_begin(sync_method_call_logger, OS_SIGNPOST_ID_EXCLUSIVE, function_name(__func__), "%s %s", moduleName, methodName);
};
 
void CxxNativeModulePerfLogger::syncMethodCallReturnConversionEnd(
                                                    const char *moduleName,
                                                    const char *methodName) {
  os_signpost_interval_end(sync_method_call_logger, OS_SIGNPOST_ID_EXCLUSIVE, function_name(__func__), "%s %s", moduleName, methodName);
};
 
void CxxNativeModulePerfLogger::syncMethodCallEnd(
                                                    const char *moduleName,
                                                    const char *methodName) {
  os_signpost_interval_end(sync_method_call_logger, OS_SIGNPOST_ID_EXCLUSIVE, function_name(__func__), "%s %s", moduleName, methodName);
  os_signpost_event_emit(points_of_interest_logger, OS_SIGNPOST_ID_EXCLUSIVE, function_name(__func__), "%s %s", moduleName, methodName);
};

void CxxNativeModulePerfLogger::syncMethodCallFail(
                                                    const char *moduleName,
                                                    const char *methodName) {
  os_signpost_event_emit(sync_method_call_logger, OS_SIGNPOST_ID_EXCLUSIVE, function_name(__func__), "%s %s", moduleName, methodName);
};

void CxxNativeModulePerfLogger::asyncMethodCallStart(
                                                    const char *moduleName,
                                                    const char *methodName) {
  os_signpost_interval_begin(async_method_call_logger, OS_SIGNPOST_ID_EXCLUSIVE, function_name(__func__), "%s %s", moduleName, methodName);
  os_signpost_event_emit(points_of_interest_logger, OS_SIGNPOST_ID_EXCLUSIVE, function_name(__func__), "%s =%s", moduleName, methodName);
};

void CxxNativeModulePerfLogger::asyncMethodCallArgConversionStart(
                                                    const char *moduleName,
                                                    const char *methodName) {
  os_signpost_interval_begin(async_method_call_logger, OS_SIGNPOST_ID_EXCLUSIVE, function_name(__func__), "%s %s", moduleName, methodName);
};

void CxxNativeModulePerfLogger::asyncMethodCallArgConversionEnd(
                                                    const char *moduleName,
                                                    const char *methodName) {
  os_signpost_interval_end(async_method_call_logger, OS_SIGNPOST_ID_EXCLUSIVE, function_name(__func__), "%s %s", moduleName, methodName);
};

void CxxNativeModulePerfLogger::asyncMethodCallDispatch(
                                                    const char *moduleName,
                                                    const char *methodName) {
  os_signpost_event_emit(async_method_call_logger, OS_SIGNPOST_ID_EXCLUSIVE, function_name(__func__), "%s %s", moduleName, methodName);
};

void CxxNativeModulePerfLogger::asyncMethodCallEnd(
                                                    const char *moduleName,
                                                    const char *methodName) {
  os_signpost_interval_end(async_method_call_logger, OS_SIGNPOST_ID_EXCLUSIVE, function_name(__func__),  "%s %s", moduleName, methodName);
};

void CxxNativeModulePerfLogger::asyncMethodCallFail( const char *moduleName, const char *methodName) {
  os_signpost_event_emit(async_method_call_logger, OS_SIGNPOST_ID_EXCLUSIVE, function_name(__func__),  "%s %s", moduleName, methodName);
};

void CxxNativeModulePerfLogger::asyncMethodCallBatchPreprocessStart() {
  os_signpost_interval_begin(async_method_call_logger, OS_SIGNPOST_ID_EXCLUSIVE, function_name(__func__));
};

void CxxNativeModulePerfLogger::asyncMethodCallBatchPreprocessEnd(int batchSize) {
  os_signpost_interval_end(async_method_call_logger, OS_SIGNPOST_ID_EXCLUSIVE, function_name(__func__), "%d", batchSize);
};

void CxxNativeModulePerfLogger::asyncMethodCallExecutionStart(const char *moduleName, const char *methodName, int32_t id) {
  os_signpost_interval_begin(async_method_call_logger, id, function_name(__func__), "%s %s", moduleName, methodName);
};

void CxxNativeModulePerfLogger::asyncMethodCallExecutionArgConversionStart(const char *moduleName, const char *methodName, int32_t id) {
  os_signpost_interval_begin(async_method_call_logger, id, function_name(__func__), "%s %s", moduleName, methodName);
};

void CxxNativeModulePerfLogger::asyncMethodCallExecutionArgConversionEnd(const char *moduleName, const char *methodName, int32_t id) {
  os_signpost_interval_end(async_method_call_logger, id, function_name(__func__), "%s %s", moduleName, methodName);
};

void CxxNativeModulePerfLogger::asyncMethodCallExecutionEnd(const char *moduleName, const char *methodName, int32_t id) {
  os_signpost_interval_end(async_method_call_logger, id, function_name(__func__), "%s %s", moduleName, methodName);
};

void CxxNativeModulePerfLogger::asyncMethodCallExecutionFail(const char *moduleName, const char *methodName, int32_t id) {
  os_signpost_event_emit(async_method_call_logger, id, function_name(__func__), "%s %s", moduleName, methodName);
};

} // namespace react
} // namespace facebook
