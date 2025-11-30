int
main ()
{
    int *heap_ptr{ new int };
    *heap_ptr = 2025;
    delete heap_ptr;
    heap_ptr = nullptr;
    return 0;
}
