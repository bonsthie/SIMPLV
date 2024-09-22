#include "simpl_ifunc.h"

simpl_ifunc_init(v32c_add, vec, vec, vec);

simpl_ifunc_init(v32c_cmpeq, vec, vec, vec);

simpl_ifunc_init(v256b_set_char, vec, char, char, char, char, char, char, char,
                 char, char, char, char, char, char, char, char, char, char,
                 char, char, char, char, char, char, char, char, char, char,
                 char, char, char, char, char);

simpl_ifunc_init(v256b_set1_char, vec, char);

simpl_ifunc_init(v32c_movemask, int, vec);

simpl_ifunc_init(v256b_loadu, vec, const uvec *);
