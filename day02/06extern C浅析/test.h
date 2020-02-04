#pragma once

////方法一
//#include <stdio.h>
//
//void show();


//方法二
#ifdef __cplusplus
extern "C" {
#endif // !__cplusplus

#include <stdio.h>

	void show();


#ifdef __cplusplus
 }
#endif // !__cplusplus
