# Hash tables

https://docs.rs/hashbrown/latest/src/hashbrown/map.rs.html#190-193
Rustでは hashbrown::hash_map::HashMapに実態が定義されている

https://docs.rs/hashbrown/latest/src/hashbrown/map.rs.html#1351-1361
hash_builderでhash生成してget

https://docs.rs/hashbrown/latest/src/hashbrown/raw/mod.rs.html#795-809


## explain its definition, properties, representation(s), and associated ADT operations.
- **definitions**: ハッシュテーブルは、キーに対して値をマッピングするデータ構造で、高速なデータ検索、挿入、削除を実現する。
- **properties**: 平均的な計算時間複雑度がO(1)の非常に高速なアクセス速度。しかし、ハッシュ衝突が発生する可能性がある。
- **expression**: 配列を用いてハッシュ値に基づくインデックスでアクセス。キーからハッシュ値を生成するハッシュ関数に依存。

## explain step-by-step how the ADT operations associated with the data structure transform it.
- **insert**: キーをハッシュ関数に通し、得られたハッシュ値をインデックスとして値を配列に格納。
- **delete**: キーのハッシュ値を計算し、対応するインデックスから値を削除。
- **search**: キーのハッシュ値を求め、そのハッシュ値のインデックスから値を取得。

## Explain how collision avoidance and collision resolution is handled in hash tables.
- **collision avoidance**: 異なるキーに対して同じhashが生成されることを衝突という。ハッシュ関数を工夫してユニークなハッシュ値が生成されるようにする。

過去のhash keyと無関係に、各keyをm個の枠の任意の一つに当確率でハッシュする
以下、何らかの形でkeyが自然数として扱える過程でいく

  - 万能ハッシュ法がなぜ一様にhash値を振り分けられる？







- **collision resolution**: チェイニング（リンクリストを使った格納）、オープンアドレッシング（別の空いているスロットに格納）などのテクニックを使用。
RustのHashMapはquadratic probing（二次関数探査法）を使っている
https://doc.rust-lang.org/std/collections/struct.HashMap.html

    - liner probing(オープンアドレッシング)
      オープンアドレッシングで使われる対応
      すべての要素をhash tableに入れる
      キーをおける空の枠に出会うまで探索(prob)する
      第二引数を探索番号とし、h(k, 0) ~ h(k, m -1)までhash tableを探し空いている枠にいれる
      こうすることで、順番にO(N)で走査する必要がなくなる
      要素削除すると歯抜けになってそれ以降の要素が失われるので困る
      削除されたスロットにマーカを置けば回避できるが、どんどんパフォーマンス悪くなる
      hash tableの大きさが固定なので、拡張時には一度作り直しが必要
      長い区間の枠がすべて使用中になり、平均探索時間が悪化する

    - quadratic probing(オープンアドレッシング)
      最初の探査の位置より、距離が探査数の二次式で表される場所を次に探査する

    - chaining (チェイン法)
      同じhash値にhashされたすべてのkeyを連結リストにする
      最悪すべて同じhash値になり連結リストと同じになってしまう
      最悪探索時間はO(n)

    - rehash
      衝突が頻発したり、hash tableがいっぱいになった場合にもっと大きいテーブルに移す処理
      枠を増やし要素をもう一度配置することで効率をあげる

# 講義ノート

どういう入力に対してどのハッシュ関数が有効なのか
攻撃にはどんなパターンがあるのか
この辺をカバーするべし

## ハッシュ法について考えるときの基本的な考え方
どうせテーブルサイズでmodを取らないといけない
あとは様々な入力に対しどの程度一様に分布させるかの勝負
