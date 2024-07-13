# Priority Queue

## explain its definition, properties, representation(s), and associated ADT operations.
- **definition**: プライオリティキューは、各要素が優先度を持ち、優先度の高い要素が先に取り出される抽象データ型です。
- **properties**: 要素の挿入は通常O(log n)、最大または最小の要素の検索および削除はO(1)で行うことができる。
- **expressions**: バイナリヒープ、フィボナッチヒープ、ビノミアルヒープなどが使用される。

## explain step-by-step how the ADT operations associated with the data structure transform it.
1. **挿入**
   - 新しい要素をヒープの最後に追加する。
   - 追加した要素をヒープの性質を満たすまで親ノードと比較し、必要に応じて交換しながら上に移動させる。

2. **削除**
   - ヒープから根（最大または最小値）を削除する。
   - ヒープの最後の要素を根に移動する。
   - 移動した要素がヒープの性質を満たすまで、子ノードと比較し、必要に応じて交換しながら下に移動させる。

3. **置換**
   - ヒープの根を新しい要素で置き換える。
   - 置換後の要素をヒープの性質を満たすまで、子ノードと比較し、必要に応じて交換しながら下に移動させる。

## Explain the heap property and the use of heaps as an implementation of a priority queue.
- **ヒープ条件**: バイナリヒープでは、全てのノードがその子ノードより大きい（または小さい）ことが保証される。
- **プライオリティキューの実装としてのヒープの使用**: プライオリティキューは効率的に優先度の高い要素を管理するためにヒープを使用する。ヒープにより、最大値または最小値へのアクセス、要素の挿入、削除が高速に行える。
