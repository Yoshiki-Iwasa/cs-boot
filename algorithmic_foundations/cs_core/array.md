# Arrays (Dynamic)
参考
- https://www.geeksforgeeks.org/what-is-array/
- https://doc.rust-lang.org/std/primitive.array.html
- https://en.wikipedia.org/wiki/Array_(data_structure)
- https://en.wikipedia.org/wiki/Dynamic_array


## explain its definition, properties, representation(s), and associated ADT operations.
- **Definition**: 動的配列は、要素が追加されるときにサイズを自動的に調整する配列。固定長の配列を基にしており、必要に応じて拡大する。
- **Properties**: 要素は配列の連続したメモリ位置に格納される。配列のサイズ（論理サイズ）と容量（物理サイズ）は異なり、容量は現在の要素数よりも大きく設定されることが多い。
- **Representations**: 配列の実装は、一般的には基礎となる固定サイズの配列と、その上に構築される。
- **Associated ADT operations**: `insert`, `delete`, `resize` などの操作が含まれる。`insert` は要素を追加し、必要に応じて配列をリサイズする。`delete` は要素を削除し、配列のサイズは変更しない。

## explain step-by-step how the ADT operations associated with the data structure transform it.
- **Insertion**: 要素を追加する際、まず配列の末尾に要素を置く。空きスペースがない場合、配列を新しい、より大きな配列に拡張してから要素を追加する。
  1. 要素を追加する位置を決定（通常は末尾）。
  2. 配列に空きがあればその位置に要素を置く。
  3. 空きがなければ配列のサイズを拡大し、全要素を新しい配列にコピー後、新しい要素を追加する。
- **Deletion**: 要素を配列から削除するときは、特定の位置の要素を削除し、後続の要素を前にシフトする。
  1. 削除する要素の位置を特定。
  2. その要素を削除し、必要に応じて後続の要素を前にシフトさせる。
  3. 配列の論理サイズを更新する。
- **Resizing**: 配列が拡大する際は、新しい、大きな配列が確保され、既存の要素が新しい配列にコピーされる。
  1. 新しい配列のサイズを決定（通常は現在のサイズの2倍など）。
  2. 新しい配列を割り当てる。
  3. 既存の配列から新しい配列に全要素をコピーする。
