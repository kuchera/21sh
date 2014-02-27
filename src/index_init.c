#include "index.h"

#include "fun_exit.h"
#include "fun_cat.h"
#include "fun_echo.h"

void i_init()
{
	i_add("exit", &fun_exit);
	i_add("cat", &fun_cat);
	i_add("echo", &fun_echo);
}
