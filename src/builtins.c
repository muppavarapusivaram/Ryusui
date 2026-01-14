#include "builtins.h"

BuiltinCommand builtins[] = {
	{"echo", echo_builtin},
	{"type", type_builtin}

};

int num_builtins() {
	return sizeof(builtins) / sizeof(builtins[0]);
}
