#pragma once

#define FILE_VERSION 1,0,0,0
#define PRODUCT_VERSION 1,0,0,0

#define STRINGIZE2(s) #s
#define STRINGIZE(s) STRINGIZE2(s)

#define FILE_VERSION_STR STRINGIZE(FILE_VERSION)
#define PRODUCT_VERSION_STR STRINGIZE(PRODUCT_VERSION)
