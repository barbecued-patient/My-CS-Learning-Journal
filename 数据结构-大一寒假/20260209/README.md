顺序存储搞明白了，也基本能写了
链式存储依旧云里雾里


一个问题：
void Attach(int coef,int expon,Polynomial *pRear)
Attach(ceof,expon,&rear);
这个函数定义和函数使用的第三项凭什么能对应上
# **这个对应关系凭什么成立？**

这是一个关于**类型匹配**和**指针转换**的重要问题。让我详细解释为什么能对应上：

## 1. **先看类型定义**

```c
// 第一步：定义结构体指针类型
typedef struct PolyNode *Polynomial;
// 解释：Polynomial 是 "struct PolyNode*" 的别名

// 第二步：根据typedef，我们得到：
Polynomial rear;  // 等价于 struct PolyNode* rear;
```

## 2. **分析函数定义**

```c
void Attach(int coef, int expon, Polynomial *pRear)
```

**展开Polynomial**：
- `Polynomial` = `struct PolyNode*`
- 所以 `Polynomial *` = `struct PolyNode* *` = `struct PolyNode**`

**因此函数定义等价于**：
```c
void Attach(int coef, int expon, struct PolyNode** pRear)
```

## 3. **分析函数调用**

```c
Attach(coef, expon, &rear);
```

**展开rear的类型**：
- `rear` 是 `Polynomial` 类型
- `Polynomial` = `struct PolyNode*`
- 所以 `rear` 是 `struct PolyNode*`
- `&rear` 是 `struct PolyNode* *` = `struct PolyNode**`

**因此函数调用等价于**：
```c
Attach(coef, expon, &rear);  // &rear 是 struct PolyNode**
```

## 4. **类型匹配验证**

| 代码部分 | 实际类型 | 是否匹配 |
|---------|---------|----------|
| **函数定义参数** | `Polynomial *pRear` | `struct PolyNode**` |
| **函数调用实参** | `&rear` | `struct PolyNode**` |
| **结论** | ✅ **完全匹配** | ✅ 都是二级指针 |
