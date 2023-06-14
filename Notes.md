# Notes

## 一些知识点记录

1.  `=default` : defined with an empty parameter list, or with default arguments provided for every parameter. 
    1. 从形式上来说，对应的书写形式就是传入 empty parameter list.  `Type t;  Type t{};`
    2. 从行为来说，对类成员执行默认初始化。对于非类对象, 使用默认值初始化; 对于类对象, 递归执行默认初始化。
2. `shared_ptr` : 在没有显式传指针初始化时，指向 nullptr
3. `make_pair` 不能显式给出实参类型，必须让编译器进行类型推导(编译期执行); 但是 `make_shared` 可以显式给出实参类型，不知道为什么
4. `const Type &` 和 `Type &&` 的区别? 