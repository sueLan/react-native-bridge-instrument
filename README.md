# ReactNativeBridgeInstrument

[![CI Status](https://img.shields.io/travis/sueLan/ReactNativeBridgeInstrument.svg?style=flat)](https://travis-ci.org/sueLan/ReactNativeBridgeInstrument)
[![Version](https://img.shields.io/cocoapods/v/ReactNativeBridgeInstrument.svg?style=flat)](https://cocoapods.org/pods/ReactNativeBridgeInstrument)
[![License](https://img.shields.io/cocoapods/l/ReactNativeBridgeInstrument.svg?style=flat)](https://cocoapods.org/pods/ReactNativeBridgeInstrument)
[![Platform](https://img.shields.io/cocoapods/p/ReactNativeBridgeInstrument.svg?style=flat)](https://cocoapods.org/pods/ReactNativeBridgeInstrument)

## Usage

Basically, you have to write a method in `mm` file to use these C++ functions.

```c++
#include <ReactNativeBridgeInstrument/CxxNativeModulePerfLogger.h>
// make sure `CXXFLAGS += -std=c++14` or 14 above in your Xcode building settings
#include <memory>

- (void)initializeInstrument
{
  facebook::react::CxxNativeModulePerfLogger logger = facebook::react::CxxNativeModulePerfLogger();
  facebook::react::BridgeNativeModulePerfLogger::enableLogging(std::make_unique<facebook::react::CxxNativeModulePerfLogger>(logger));
}
```

## In Instrument 

1. Open the instrument,  choose `Blank` template in Instrument 

   ![image-20210926173249306](https://tva1.sinaimg.cn/large/008i3skNgy1guu5vkkpu7j61880aemyj02.jpg)

2. Then , add `os_signpost`  to current template,  and start recording. 

   ![image-20210926173031427](https://tva1.sinaimg.cn/large/008i3skNgy1gv18fu3r64j628009c40202.jpg)

3. pay attention to our customed logger Volume. There are 4 parts, 

- `async_method_call`:  collect data for asynchronous methods running through JSBridge
- `js_require`  : used to calculate time interval to initialize modules 
- `module` : used to calculate time interval to create `RCTModuleData` 
- `sync_method_call` :  collect data for synchronous methods running through JSBridge![image-20210926174136104](https://tva1.sinaimg.cn/large/008i3skNgy1gv18fv7bi9j61ht0u0wjn02.jpg)![image-20210926175209847](https://tva1.sinaimg.cn/large/008i3skNgy1gv18hjuyerj61jk0u0ti402.jpg)