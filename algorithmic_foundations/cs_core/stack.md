# Stack

## explain its definition, properties, representation(s), and associated ADT operations.
- **definitions**: スタックは後入れ先出し（LIFO）の原則に基づく抽象データ型で、最後に追加された要素が最初に取り出される。
- **properties**: スタック操作はO(1)で実行可能で、非常に効率的。しかし、ランダムアクセスには適しておらず、中間の要素への直接的なアクセスが不可能。
- **expressions**: スタックは通常、配列または連結リストを使用して実装される。配列ベースの実装ではインデックスを使用し、連結リストベースではノード間のポインタを利用。
- **ADT operations**: `push`（要素の追加）、`pop`（最後の要素の削除と返却）、`peek`（最後の要素の参照）、`isEmpty`（スタックが空かどうかの確認）。

## explain step-by-step how the ADT operations associated with the data structure transform it.
- **Push**: 新しい要素をスタックのトップに追加し、トップのポインタ（またはインデックス）を更新。
- **Pop**: スタックのトップにある要素を削除し、その要素を返却。トップのポインタを一つ下の要素に移動。
- **Peek**: スタックのトップにある要素を読み取るが、その位置に残す。
- **isEmpty**: スタックが空かどうかをチェックし、空の場合はtrueを、そうでない場合はfalseを返す。
