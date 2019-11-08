#include "string.h"

#include "../headers/struct.h"
#include "../f_headers/add_titanicgame.h"
#include "../f_headers/create_titanicgame.h"
#include "../d_trees_headers/saburov_d6n_tree_titanicgame.h"

bool age_definer(passenger runner)
{
    if (runner.age == -1)
    {
        return FALSE;
    }

    if (runner.age > 16)
    {
        return FALSE;
    }

    return TRUE;
}

bool sex_definer(passenger runner)
{
    if (strcmp(runner.sex, "female"))
        return FALSE;
    else
        return TRUE;
}

bool pclass_definer(passenger runner)
{
    if (runner.pclass > 2)
        return FALSE;
    else
        return TRUE;
}

bool relat_definer (passenger runner)
{
    if (runner.siblings_sp || runner.parch)
        return TRUE;
    else
        return FALSE;
}
node *saburov_d6n_tree_titanicgame()
{
    node *root = create(sex_definer);
    node *yes = create(age_definer);
    node *yes_no = create(relat_definer);

    node *no = create(age_definer);
    node *no_yes = create(pclass_definer);

    add(root, TRUE, yes);
    add(yes, FALSE, yes_no);
    add(root, FALSE, no);
    add(no, TRUE, no_yes);

    return root;
}
