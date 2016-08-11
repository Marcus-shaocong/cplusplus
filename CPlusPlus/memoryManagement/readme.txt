make explicit decisions about ownership and lifetime before you start to code

Solid object
collection of solid objects, it goes away when the class is goes away
unique_ptr(or collection of them) also it goes away when the class is goes away, need to implement the copy ctor and copy assignment to make sure the unique_ptr is copyable.
shared_ptr(or collection of them) I use that, and it goes away after the class is run away
Raw pointer (no impact on lifetime) I don't control its lifetime, I only use it


Understand the consequences of the mechanism you choose
Uncopyable
Need(or not) to write a copy ctor/copy assign op


A way to observer/access something without impact on its lifetime

1.if the read object is in a shared_ptr, use a week_ptr
  Can ask it whether the real object still exists
2.if the read object is in a unique_ptr, use a raw pointer with care
the get()method will provide access to the raw pointer
Can check whether read object still exists

if the read object is solid, use a raw pointer(from & operator or a this) with care
  can check if pointer is nullptr- not a complete check

Shared access to an objet on the free store
Lifetime can be complicated to manage
not as common as most people think at first
Use a shared_ptr, this is exactly what it's for

