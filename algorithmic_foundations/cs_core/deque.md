# Double-ended queue

## explain its definition, properties, representation(s), and associated ADT operations.
- **definitions**: ダブルエンデッドキューは、両端から要素の追加や削除が可能な抽象データ型である。
- **properties**: 両端からの操作をO(1)で行うことができ、配列や連結リストを用いた効率的な実装が可能。ランダムアクセスも可能。
- **representations**: 配列ベースでは循環バッファを使用し、連結リストベースでは双方向リンクリストを使用する。
- **ADT operations**: 両端への要素の追加（push_front, push_back）、両端からの要素の削除（pop_front, pop_back）、両端の要素の覧（peek_front, peek_back）。

## explain step-by-step how the ADT operations associated with the data structure transform it.
- **push_front**: 新しい要素をキューの前面に追加し、前面のポインタを更新。
- **push_back**: 新しい要素をキューの後ろに追加し、後ろのポインタを更新。
- **pop_front**: 前面の要素を削除し、前面のポインタを次の要素に移動。
- **pop_back**: 後ろの要素を削除し、後ろのポインタを前の要素に移動。
- **peek_front / peek_back**: 前面または後ろの要素を返すが、削除はしない。
