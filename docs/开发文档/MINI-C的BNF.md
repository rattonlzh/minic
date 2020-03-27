# BNF
1. program→ declaration-list
2. declaration-list→ declaration-list declaration | declaration
3. declaration→ var-declaration | fun-declaration
4. var-declaration→ type-specifier ID ;|type-specifier ID[NUM];
5. type-specifier→ int | void
6. fun-declaration→ type-specifier ID(params) compound-stmt
7. params→params-list | void
8. param-list→param-list, param | param
9.  param→ type-specifier ID | type-specifier ID[ ]
10. compound-stmt→ { local-declarations statement-list }
11. local-declarations→ local-declarations var-declaration |empty
12. statement-list→ statement-list statement | empty
13. statement→expression-stmt | compound-stmt | selection-stmt
|iteration-stmt | return-stmt
14. expression-stmt→ expression ; | ;
15. selection-stmt→ if(expression) statement
|if(expression)statement else statement
16. iteration-stmt→while( expression) statement
17. return-stmt→return ;| return expression ;
18. expression→ var=expression | simple-expression
19. var→ID |ID[expression]
20. simple-expression→additive-expression relop additive-expression
|additive-expression
21. relop→<=|<|>|>=|==|!=
22. additive-expression→additive-expression addop term | term
23. addop→+|-
24. term→term mulop factor | factor
25. mulop→*|/
26. factor→(expression )| var | call | NUM
27. call→ID(args)
28. args→arg-list | empty
29. arg-list→arg-list,expression | expression


对以上每条文法规则,给出了相关语义的简短解释。
1.program→ declaration-list
2.declaration-list→declaration-list declaration |declaration
3.declaration→var-declaration | fun-declaration
程序由声明的列表(或序列)组成,声明可以是函数或变量声明,顺序是任意的。至少必须
有一个声明。接下来是语义限制(这些在 C 中不会出现)。所有的变量和函数在使用前必须声
明(这避免了向后 backpatching 引用)。程序中最后的声明必须是一个函数声明,名字为
main。注意,Mini C 缺乏原型,因此声明和定义之间没有区别(像 C 一样)。4.var-declaration→type-specifier ID ;|type-specifier ID[NUM];
5.type-specifier→int|void
变量声明或者声明了简单的整数类型变量,或者是基类型为整数的数组变量,索引范围从
0 到 NUM-1。注意,在 Mini C 中仅有的基本类型是整型和空类型。在一个变量声明中,只能使
用类型指示符 int。void 用于函数声明(参见下面)。也要注意,每个声明只能声明一个变
量。
6.fun-declaration→ type-specifier ID( params )compound-stmt
7.params→param-list | void
8.param-list→param-list, param | param
9.param→type-specifier ID | type-specifier ID [ ]
函数声明由返回类型指示符、标识符以及在圆括号内的用逗号分开的参数列表组成,后
面跟着一个复合语句,是函数的代码。如果函数的返回类型是 void,那么函数不返回任何值
(即是一个过程)。函数的参数可以是 void(即没有参数),或者一列描述函数的参数。参数后
面跟着方括号是数组参数,其大小是可变的。简单的整型参数由值传递。数组参数由引用来
传递(也就是指针),在调用时必须通过数组变量来匹配。注意,类型“函数”没有参数。一个
函数参数的作用域等于函数声明的复合语句,函数的每次请求都有一个独立的参数集。函数
可以是递归的(对于使用声明允许的范围)
10.compound-stmt →{local-declarations statement-list }
复合语句由用花括号围起来的一组声明和语句组成。复合语句通过用给定的顺序执行语
句序列来执行。局部声明的作用域等于复合语句的语句列表,并代替任何全局声明。
11.local-declarations→local-declarations var-declaration | empty
12.statement-list→statement-list statement | empty
注意声明和语句列表都可以是空的(非终结符 empty 表示空字符串,有时写作。)
13.statement→ expression-stmt
|compound-stmt
|selection-stmt
|iteration-stmt
|return-stmt
14.expression-stmt→expression;|;
表达式语句有一个可选的且后面跟着分号的表达式。这样的表达式通常求出它们一方的
结果。因此,这个语句用于赋值和函数调用。
15.selection-stmt→if(expression) statement
|if(expression)statement else statement
if 语句有通常的语义:表达式进行计算;非 0 值引起第一条语句的执行;0 值引起第二条
语句的执行,如果它存在的话。这个规则导致了典型的悬挂 else 二义性,可以用一种标准的
方法解决:else 部分通常作为当前 if 的一个子结构立即分析(“最近嵌套”非二义性规
则)。
16.iteration-stmt→while (expression) statement
while 语句是 Mini C 中唯一的重复语句。它重复执行表达式,并且如果表达式的求值为
非 0,则执行语句,当表达式的值为 0 时结束。
17.return-stmt→ return ;| return expression ;
返回语句可以返回一个值也可无值返回。函数没有说明为 void 就必须返回一个值。函
数声明为 void 就没有返回值。 return 引起控制返回调用者(如果它在 main 中,则程序结
束)。
18.expression→var = expression | simple-expression
19.var→ID |ID[expression]
表达式是一个变量引用,后面跟着赋值符号(等号)和一个表达式,或者就是一个简单的表
达式。赋值有通常的存储语义:找到由 var 表示的变量的地址,然后由赋值符右边的子表达式
进行求值,子表达式的值存儲到给定的地址。这个值也作为整个表达式的值返回。var 是简
单的(整型)变量或下标数组变量。负的下标将引起程序停止(与 C 不同)。然而,不对其进行
下标越界检査。
var 表示 Mini C 比 C 有进一步的限制。在 C 中赋值的目标必须是左值(l-value),左
值是可以由许多操作获得的地址。在 Mini C 中唯一的左值是由 var 语法给定的,因此这个种
类按照句法进行检查,代替像 C 中那样的类型检查。故在 Mini C 中指针运算是禁止的。
20.simple-expression→additive-expression relop additive-expression
|additive-expression
21.relop→<=|<|>|>=|==|!=
简单表达式由无结合的关系操作符组成(即无括号的表达式仅有一个关系操作符)。简单
表达式在它不包含关系操作符时,其值是加法表达式的值,或者如果关系算式求值为 true,其
值为 1,求值为 false 时值为 0。
22.additive-expression→ additive-expression addop term | term
23.adop→+|-
24.term→term mulop factor | factor
25.mulop→*|/
加法表达式和项表示了算术操作符的结合性和优先级。符号表示整数除;即任何余数都
被截去。
26.factor→ (expression)| var | call | NUM
因子是围在括号内的表达式;或一个变量,求出其变量的值;或者一个函数调用,求出函数
的返回值;或者一个 NUM,其值由扫描器计算。数组变量必须是下标变量,除非表达式由单个
ID 组成,并且以数组为参数在函数调用中使用(如下所示)。27.call→ ID( args)
28.args→ arg-list | empty
29.arg-list→ arg-list,expression | expression
函数调用的组成是一个 ID(函数名),后面是用括号围起来的参数。参数或者为空,或者
由逗号分割的表达式列表组成,表示在一次调用期间分配的参数的值。函数在调用之前必须
声明,声明中参数的数目必须等于调用中参数的数目。函数声明中的数组参数必须和一个表
达式匹配,这个表达式由一个标识符组成表示一个数组变量。
最后,上面的规则没有给出输入和输出语句。在 Mini C 的定义中必须包含这样的函数,
因为与 C 不同,Mini C 没有独立的编译和链接工具;因此,考虑两个在全局环境中预定义的函
数,好像它们已进行了声明:
int input(void){ ...}
void output(int x){ ... }
input 函数没有参数,从标准输入设备(通常是键盘)返回一个整数值。 output 函数接受
一个整型参数,其值和一个换行符一起打印到标准输出设备(通常是屏幕)