int     main(int argc, char **argv)
{
    check_args();

    parsing();

    launch_game();

    throw_save();

    return(0);
}