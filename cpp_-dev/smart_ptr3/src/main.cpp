#include <iostream>
#include <memory>
#include <ostream>

int
main ()
{
    std::shared_ptr<int> s_ptr = std::make_shared<int> (100);
    std::cout << "shared_ptr is: " << s_ptr.use_count () << std::endl;

    std::weak_ptr<int> w_ptr = s_ptr;

    std::shared_ptr<int> lock_ptr = w_ptr.lock ();

    if (lock_ptr)
        {
            std::cout << "locked value" << *lock_ptr << std::endl;
            std::cout << "shared_ptr after weak_ptr set: "
                      << s_ptr.use_count () << std::endl;
        }
    else
        {
            std::cout << "locked failed" << std::endl;
        }

    std::cout << "lock_ptr leave: " << s_ptr.use_count () << std::endl;

    s_ptr = nullptr;
    std::cout << "s_ptr reseted" << s_ptr.use_count () << std::endl;

    return 0;
}
