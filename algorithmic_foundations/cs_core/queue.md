# Queue

## explain its definition, properties, representation(s), and associated ADT operations.
- **definitions**: キューは先入れ先出し（FIFO）の原則に基づくコレクションで、要素は一端から追加され、反対側から削除される。
- **properties**: 追加と削除の操作がO(1)で行える高効率性を持つ。ランダムアクセスには適していない。
- **expressions**: 配列や連結リスト、循環バッファーを使用して実装されることが多い。動的な配列での実装も一般的。
- **ADT operations**: enqueue（要素の追加）、dequeue（要素の削除と取得）、peek（先頭要素の参照）。

## explain step-by-step how the ADT operations associated with the data structure transform it.
- **Enqueue**: キューの末尾に要素を追加し、末尾のポインタを更新。
- **Dequeue**: キューの先頭から要素を削除し、その要素を返し、先頭のポインタを次の要素に移動。
- **Peek**: キューの先頭にある要素を返すが、削除はしない。
