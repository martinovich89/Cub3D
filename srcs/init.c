void	init_params(t_env *env)
{
    env->conf.res_w = -1;
    env->conf.res_h = -1;
    env->conf.path_no = NULL;
    env->conf.path_ea = NULL;
    env->conf.path_we = NULL;
    env->conf.path_so = NULL;
    env->conf.path_np = NULL;
    env->conf.ceil_r = 0;
    env->conf.ceil_g = 0;
    env->conf.ceil_b = 0;
    env->conf.ceil_is_set = 0;
    env->conf.floo_r = 0;
    env->conf.floo_g = 0;
    env->conf.floo_b = 0;
    env->conf.floo_is_set = 0;
}
