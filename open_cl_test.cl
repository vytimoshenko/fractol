__kernel void open_cl_test(__global int *buf)
{
    int i = get_global_id(0);
    buf[i] += i + 65536;
    float r;

    if (i == 0)
    {
        printf("\nKERNEL INFO:\nglobal_size: %d, num_groups: %d, local_size: %d\n\n", 
        get_global_size(0), get_num_groups(0), get_local_size(0));

        r = 0.261799;
        r = native_sin(r);
        printf("%f ", r);

        r = 0.523599;
        r = native_sin(r);
        printf("%f ", r);

        r = 0.785398;
        r = native_sin(r);
        printf("%f ", r);

        r = 1.0472;
        r = native_sin(r);
        printf("%f ", r);

        r = 1.309;
        r = native_sin(r);
        printf("%f ", r);

        r = 1.5708;
        r = native_sin(r);
        printf("%f\n", r);

        r = 0.261799;
        r = sin(r);
        printf("%f ", r);

        r = 0.523599;
        r = sin(r);
        printf("%f ", r);

        r = 0.785398;
        r = sin(r);
        printf("%f ", r);

        r = 1.0472;
        r = sin(r);
        printf("%f ", r);

        r = 1.309;
        r = sin(r);
        printf("%f ", r);

        r = 1.5708;
        r = sin(r);
        printf("%f\n", r);
    }
    printf("group_id %d, local_id: %d, global_id %d\n", get_group_id(0), get_local_id(0), buf[i]);
}