/* Copyright 2013 David Axmark

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

	http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#ifndef NBUILD_H
#define NBUILD_H

#include <vector>
#include <string>
#include <map>

#include "args.h"

using namespace std;

#define MACRO_DEFINES "-D"
#define SOURCE_FILE "-S"
#define EXCLUDE_FILE "-X"
#define ADDITIONAL_INCLUDES "-I"
#define ADDITIONAL_LIB_PATHS "-L"

#define NAME "--name"
#define CONFIGURATION "--config"
#define BINARY_TYPE "--lib-variant" // 'debug' or 'release'
#define PROJECT_DIR "--project"
#define OUTPUT_DIR "--dst"
#define BOOT_MODULE_LIST "--boot-modules"
#define MODULE_LIST "--modules"
#define EXCLUDE_FILES "--exclude-files"
#define VERBOSE "--verbose"
#define CLEAN "--clean"
#define COMPILER_SWITCHES "--compiler-switches"

#define IOS_SDK "--ios-sdk"
#define IOS_SDK_VERSION "--ios-sdk-version"
#define IOS_XCODE_TARGET "--ios-xcode-target"
#define IOS_XCODE_LOCATION "--ios-xcode-location"

string require(Arguments* args, string key);

/**
 * Returns the set of source files to compile, using SOURCE_FILE
 * and EXCLUDE_FILE preixes. Returns a list of files relative to
 * the PROJECT_DIR.
 */
vector<string> getSourceFiles(Arguments* args);

/**
 * Validates a configuration name
 * \return a non-empty string describing what is wrong,
 * or an empty string if valid
 */
string validateConfiguration(string& configName);

bool isSTL(string& name);

const char* mosyncdir();
int sh(const char* cmd, bool hideOutput = false, const char* shownCmdLine = 0, bool exitOnError = true);
void error(const char* msg, int errorCode = 1);

#endif
