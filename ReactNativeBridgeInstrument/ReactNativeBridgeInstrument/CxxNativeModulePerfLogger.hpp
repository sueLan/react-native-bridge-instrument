//
//  CxxNativeModulePerfLogger.hpp
//  RNTester
//
//  Created by Zheng Rongyan on 7/3/21.
//  Copyright © 2021 Facebook. All rights reserved.
//

#ifndef CxxNativeModulePerfLogger_hpp
#define CxxNativeModulePerfLogger_hpp

#include <stdio.h>
#include <reactperflogger/NativeModulePerfLogger.h>
#include <os/signpost.h>
#include <os/log.h>

namespace facebook {
namespace react {

class CxxNativeModulePerfLogger: public NativeModulePerfLogger {
private:
  os_log_t module_os_logger;
  os_log_t js_require_os_logger;
  os_log_t sync_method_call_logger;
  os_log_t async_method_call_logger;
  os_log_t points_of_interest_logger;
public:
  CxxNativeModulePerfLogger();
  
  void moduleDataCreateStart(const char *moduleName, int32_t id);
  void moduleDataCreateEnd(const char *moduleName, int32_t id);
  void moduleCreateStart(const char *moduleName, int32_t id);
  void moduleCreateCacheHit(const char *moduleName, int32_t id);

  void moduleCreateConstructStart(
     const char *moduleName,
                                  int32_t id);
  void moduleCreateConstructEnd(const char *moduleName, int32_t id);
  void moduleCreateSetUpStart(const char *moduleName, int32_t id);
  void moduleCreateSetUpEnd(const char *moduleName, int32_t id);
  void moduleCreateEnd(const char *moduleName, int32_t id);
  void moduleCreateFail(const char *moduleName, int32_t id);

  void moduleJSRequireBeginningStart(const char *moduleName);
  void moduleJSRequireBeginningCacheHit(const char *moduleName);
  void moduleJSRequireBeginningEnd(const char *moduleName);
  void moduleJSRequireBeginningFail(const char *moduleName);

  void moduleJSRequireEndingStart(const char *moduleName);
  void moduleJSRequireEndingEnd(const char *moduleName);
  void moduleJSRequireEndingFail(const char *moduleName);

  void syncMethodCallStart(
      const char *moduleName,
                           const char *methodName);
  void syncMethodCallArgConversionStart(
     const char *moduleName,
                                        const char *methodName);
  void syncMethodCallArgConversionEnd(
      const char *moduleName,
                                      const char *methodName);
  void syncMethodCallExecutionStart(
      const char *moduleName,
                                    const char *methodName);
  void syncMethodCallExecutionEnd(
      const char *moduleName,
                                  const char *methodName);
  void syncMethodCallReturnConversionStart(
      const char *moduleName,
                                           const char *methodName);
  void syncMethodCallReturnConversionEnd(
      const char *moduleName,
                                         const char *methodName);
  void syncMethodCallEnd(
      const char *moduleName,
                         const char *methodName);
  void syncMethodCallFail(
     const char *moduleName,
                          const char *methodName);
  void asyncMethodCallStart(
      const char *moduleName,
                            const char *methodName);
  void asyncMethodCallArgConversionStart(
     const char *moduleName,
                                         const char *methodName);
  void asyncMethodCallArgConversionEnd(
      const char *moduleName,
                                       const char *methodName);
  void asyncMethodCallDispatch(
      const char *moduleName,
                               const char *methodName);
  void asyncMethodCallEnd(
      const char *moduleName,
                          const char *methodName);
  void asyncMethodCallFail(
      const char *moduleName,
                           const char *methodName);
  void asyncMethodCallBatchPreprocessStart();
  void asyncMethodCallBatchPreprocessEnd(int batchSize);
  void asyncMethodCallExecutionStart(
      const char *moduleName,
      const char *methodName,
                                     int32_t id);
  void asyncMethodCallExecutionArgConversionStart(
      const char *moduleName,
      const char *methodName,
                                                  int32_t id);
  void asyncMethodCallExecutionArgConversionEnd(
     const char *moduleName,
     const char *methodName,
                                                int32_t id);
  void asyncMethodCallExecutionEnd(
     const char *moduleName,
     const char *methodName,
                                   int32_t id);
  void asyncMethodCallExecutionFail(
      const char *moduleName,
      const char *methodName,
                                    int32_t id);
};

} // namespace react
} // namespace facebook

#endif /* CxxNativeModulePerfLogger_hpp */

