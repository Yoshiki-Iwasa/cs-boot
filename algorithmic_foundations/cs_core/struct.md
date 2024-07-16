# Struct (Class)

https://en.wikipedia.org/wiki/Struct_(C_programming_language)
調べるとなぜか`in C`で出てくるが、だいたいどの言語も同じなのでC言語で考えてみる

## explain its definition, properties, representation(s), and associated ADT operations.
- **Definition**: structは、複数の変数を一つの名前の下に物理的にグループ化し、単一のポインターや名前でアクセス可能な複合データ型。
- **Properties**: structは連続するメモリブロックを参照し、各フィールドは開始位置から固定オフセットに位置する。フィールドのアライメントは実装依存で、パディングが含まれる場合もある。
- **Representations**: メモリ内で、structは連続したフィールドとして表現される。
- **Associated ADT operations**: structの宣言、初期化、代入、ポインタを通じたアクセス。

## explain step-by-step how the ADT operations associated with the data structure transform it.
- **Declaration**: structを宣言してメンバを定義する。
```rust
  struct Point {
      x: i32,
      y: i32,
  }
```
- **Initialization**: structの変数を具体的な値で初期化する。
```rust
let point = Point { x: 10, y: 20 };
```
- **Field Access**: 一つのstructから別のstructへ値を代入する。
```rust
let x = point.x;
```
- **Field Update**: ポインタを使用してstructのメンバにアクセスし、値を変更する。
```rust
let mut point = Point { x: 10, y: 20 };
point.x = 30;
```

- **method**: Structの振る舞いを定義するために関数を設定できる

```rust
impl Point {
    pub fn vector_sum(&self) -> i32 {
        self.x + self.y
    }
}
let point = Point { x: 10, y: 20 };
point.sum() // 30
```
