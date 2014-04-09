#include "index.h"

#include "fun_cat.h"
#include "fun_cd.h"
#include "fun_clear.h"
#include "fun_display.h"
#include "fun_echo.h"
#include "fun_exit.h"
#include "fun_help.h"
#include "fun_ls.h"
#include "fun_man.h"
#include "fun_mkdir.h"
#include "fun_pwd.h"
#include "fun_time.h"
#include "fun_rm.h"
#include "fun_vp.h"

void i_init()
{
	i_add("cat", &fun_cat);
	i_add("cd", &fun_cd);
	i_add("clear", &fun_clear);
	i_add("display", &fun_display);
	i_add("echo", &fun_echo);
	i_add("exit", &fun_exit);
	i_add("help", &fun_help);
	i_add("ls", &fun_ls);
	i_add("man", &fun_man);
	i_add("mkdir", &fun_mkdir);
	i_add("pwd", &fun_pwd);
	i_add("time", &fun_time);
	i_add("rm", &fun_rm);
	i_add("vp", &fun_vp);
}
