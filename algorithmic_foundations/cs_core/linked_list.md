# Linked List
- https://www.geeksforgeeks.org/advantages-and-disadvantages-of-linked-list/
- https://en.wikipedia.org/wiki/Linked_list


## History
- リンクリストは1955-1956年にAllen Newell, Cliff Shaw, Herbert A. Simonによって開発された。主に人工知能プログラムの開発に利用された。

## Single vs Double
- 単方向リンクリストは各ノードが次のノードへのリンクのみを持つ。双方向リンクリストは次と前の両方のノードへのリンクを持つ
  双方向リストでは逆方向トラバースが可能

## Linear vs Circular
- 線形リンクリストでは最後のノードがnullを指し示す。循環リンクリストでは最後のノードが最初のノードを指し示す。

## explain its definition, properties, representation(s), and associated ADT operations.
- **definitions**: データ要素の線形集合で、物理的な配置ではなく各要素が次を指す。
- **properties**: 挿入や削除が効率的。しかし、ランダムアクセスには不向き。メモリ利用が非連続
- **expression**: ノードはデータと次のノードへの参照（リンク）を含む。
- **ADToperations**: 要素の挿入、削除、探索。

## explain step-by-step how the ADT operations associated with the data structure transform it.
- **Insertion**: 特定の位置に新しいノードを挿入し、前後のノードのリンクを更新する。
                 pointer fieldを更新して別のnodeを指すようにする
- **Deletion**: 特定のノードをリストから削除し、前後のノードのリンクを更新する。
- **Search**: リストの先頭から始めて、特定のデータを持つノードを見つけるまでノードをたどる。

# Linked Listが有用な具体的な場面って？
- データの数が読めない、どこにデータを保存すればいいかわからないパターン

- linux カーネルの構造体
  ユーザーが何個スレッドを立てるか分からないときにlinked listを使うらしい
  新しいプロセスが出てきたらinsertしたり、次のprocessの処理に移動するときなど
  無限スクローリングを実装するときに使用した
