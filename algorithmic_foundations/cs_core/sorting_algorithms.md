# Sorting Algorithms

# Stable sorting algorithm

## Overview
- 安定ソートアルゴリズムは、同じソートキーを持つ要素の相対的な順序を保持する。これは、ソート後も元のデータ内での順序が変わらないことを意味する。
- 安定でないソートアルゴリズムの例としてクイックソートがあり、安定なソートアルゴリズムの例としてマージソートがある。
- 安定性は、アルゴリズムの難易度とは無関係。しかし、特定のアプリケーションでは、要素の初期順序を保持することが重要になることがある。

## Sorting algorithms comparison
- 安定なソートアルゴリズムと安定でないソートアルゴリズムは、それぞれ異なる用途や状況で優れている場合がある。
- 例えば、マージソートは安定なソートであり、データのマージ中に元の順序を保持することができる。これに対して、クイックソートは非常に高速だが、安定性は保証されない。

## Why stability matters
- 安定性が重要なのは、複数のフィールドに基づいて段階的にソートを行う場合や、データの元の順序に意味がある場合など。
- 例えば、名前でソートされたリストを、その後生年月日で再ソートする場合、名前のソートが安定であれば、同じ生年月日の人々は名前のアルファベット順に保たれる。

## Example scenario
- データセットには、名前と生年月日のフィールドが含まれており、まず名前でソートし、その後生年月日でソートする必要がある。安定ソートを使用すると、最初のソート順序を二番目のソート処理が尊重する。


# O(n^2)

# Insertion Sort

## explain step-by-step how the algorithm operates.
- 配列を左から右へ進みながら、各要素を取り出して、それより左側にある適切な位置に挿入する。
- 挿入する位置を見つけるために、選択された要素より大きい（または小さい）すべての要素を右にシフトする。
- 適切な位置が見つかったら、そこに要素を挿入する。

## For each algorithmic approach, apply a prototypical example of the approach
```rust
fn insertion_sort(arr: &mut [i32]) {
    for i in 1..arr.len() {
        let key = arr[i];
        let mut j = i;
        while j > 0 && arr[j - 1] > key {
            arr[j] = arr[j - 1];
            j -= 1;
        }
        arr[j] = key;
    }
}
```
## Given requirements for a problem, develop multiple solutions using various data structures and algorithms. Subsequently, evaluate the suitability, strengths, and weaknesses selecting an approach that best satisfies the requirements.

挿入ソートは小さい配列やほぼ整列されたデータに対して高速であるが、大規模なデータには非効率的。


## Explain factors beyond computational efficiency that influence the choice of algorithms, such as programming time, maintainability, and the use of application-specific patterns in the input data.

挿入ソートは実装が簡単で、データがほぼ整列している場合には効率的。データの状態やサイズによって適切なアルゴリズムを選ぶ必要がある。

# Selection Sort

## explain step-by-step how the algorithm operates.
- 配列全体を未ソートとして扱い、最小（または最大）の要素を見つける。
- この要素を配列の先頭と交換し、未ソート部分の先頭を一つ右に移動。
- 未ソート部分がなくなるまでこのプロセスを繰り返す。

## For each algorithmic approach, apply a prototypical example of the approach
```rust
fn selection_sort(arr: &mut [i32]) {
    let len = arr.len();
    for i in 0..len {
        let mut min_idx = i;
        for j in i + 1..len {
            if arr[j] < arr[min_idx] {
                min_idx = j;
            }
        }
        arr.swap(i, min_idx);
    }
}
```
## Given requirements for a problem, develop multiple solutions using various data structures and algorithms. Subsequently, evaluate the suitability, strengths, and weaknesses selecting an approach that best satisfies the requirements.

選択ソートは単純で理解しやすいが、計算量はO(n^2)となり大量のデータには向かない。

## Explain factors beyond computational efficiency that influence the choice of algorithms, such as programming time, maintainability, and the use of application-specific patterns in the input data.

選択ソートはデータが少ないか事前にある程度整列されている場合に効果的。しかし、データ量が増えると非効率的になる

# O(n log n)


# Quick Sort

## explain step-by-step how the algorithm operates.
- **ピボット選択**: 配列からピボットとなる要素を選択する。
- **分割**: 配列をピボットを基準にしてピボットより小さい要素と大きい要素の2つの部分配列に分割する。
- **再帰**: 分割された各部分配列に対して再帰的にクイックソートを適用する。
- **結合**: 分割された部分配列が十分小さくなったら（通常は要素が0か1）、再帰が終了し、ソートされた配列が得られる。

## For each algorithmic approach, apply a prototypical example of the approach
```rust
fn quick_sort(arr: &mut [i32]) {
    if arr.len() <= 1 {
        return;
    }
    let pivot_index = partition(arr);
    quick_sort(&mut arr[0..pivot_index]);
    quick_sort(&mut arr[pivot_index + 1..]);
}

fn partition(arr: &mut [i32]) -> usize {
    let pivot = arr[arr.len() / 2];
    let mut i = 0;
    let mut j = arr.len() - 1;
    while i <= j {
        while arr[i] < pivot {
            i += 1;
        }
        while arr[j] > pivot {
            j -= 1;
        }
        if i <= j {
            arr.swap(i, j);
            i += 1;
            j -= 1;
        }
    }
    i
}
```

## Given requirements for a problem, develop multiple solutions using various data structures and algorithms. Subsequently, evaluate the suitability, strengths, and weaknesses selecting an approach that best satisfies the requirements.

クイックソートは平均計算時間がO(n log n)で、一般的に非常に高速。しかし、最悪の場合はO(n^2)になることもある。
### ピボットの選び方
1. **ランダムピボット**
方法: 配列内からランダムに要素を選ぶ。
利点: ランダムな選択により、事前にソートされたデータに対しても平均的に良好な性能を発揮することが期待される。
欠点: ランダム性に依存するため、最悪の場合の性能が保証されない。
2. **中央値ピボット**
方法: 配列の最初、中間、最後の要素の中から中央値を選ぶ（"median-of-three"）。
利点: より均等にデータを分割できる可能性が高く、平均的な性能が向上する。
欠点: 中央値を計算するための追加的なステップが必要。
3. **最初または最後の要素**
方法: 配列の最初または最後の要素をピボットとして選ぶ。
利点: 実装が簡単。
欠点: データが事前にソートされている場合、パフォーマンスが非常に悪くなる可能性がある（最悪の場合O(n^2)）。
4. **中央値の中央値**
方法: 複数の「小さな」グループに分割し、各グループの中央値を取り、その中央値の中央値をピボットとして選ぶ。
利点: よりバランスの取れた分割が期待され、大規模なデータセットに対して効率的。
欠点: 実装が複雑で、計算コストが高い。

## Explain factors beyond computational efficiency that influence the choice of algorithms, such as programming time, maintainability, and the use of application-specific patterns in the input data.

- クイックソートは、実装が比較的簡単であり、小さなデータセットや平均的なケースにおいて非常に効率的。

- データがあらかじめソートされている場合や、特定のパターンを持つ場合、最悪の計算時間を避けるために別のソートアルゴリズムを選択することが望ましい。

# Merge Sort

## explain step-by-step how the algorithm operates.
- 配列を最も小さな単位まで分割する。通常は各部分が1つの要素を持つまで再帰的に半分に分割する。
- 分割した部分配列を再びマージしながらソートする。このステップで、実際のソート処理が行われる。
- 2つの部分配列を順番に比較し、小さい順（または指定された順序に応じて）にマージしていく。

## For each algorithmic approach, apply a prototypical example of the approach
```python
def merge_sort(aList):
    if len(aList) <= 1:
        return aList

    mid = len(aList) // 2
    left = aList[:mid]
    right = aList[mid:]

    left = merge_sort(left)
    right = merge_sort(right)

    return list(merge(left, right))


def merge(left, right):
    sorted_list = []
    left_index = 0
    right_index = 0

    while left_index < len(left) and right_index < len(right):
        if left[left_index] <= right[right_index]:
            sorted_list.append(left[left_index])
            left_index += 1
        else:
            sorted_list.append(right[right_index])
            right_index += 1

    if left:
        sorted_list.extend(left[left_index:])
    if right:
        sorted_list.extend(right[right_index:])

    return sorted_list
```

## Given requirements for a problem, develop multiple solutions using various data structures and algorithms. Subsequently, evaluate the suitability, strengths, and weaknesses selecting an approach that best satisfies the requirements.

- マージソートは安定したソートアルゴリズムで、平均と最悪のケースの時間複雑性がO(n log n)であるため、大量のデータや重複が多いデータに適している。

## Explain factors beyond computational efficiency that influence the choice of algorithms, such as programming time, maintainability, and the use of application-specific patterns in the input data.

- マージソートは再帰的なアルゴリズムであるため、理解しやすく、実装が直観的である。しかし、追加のメモリを必要とするため、メモリ使用の制約がある環境では不利かもしれない。

- データの特性やアプリケーションの要求に応じて、メモリ使用と実行時間のバランスを取る必要がある。

# Timsort

## explain step-by-step how the algorithm operates.
- Timsortはマージソートと挿入ソートの技法を組み合わせたハイブリッドソートアルゴリズムである。
- 最初に、配列を複数の小さなブロック（またはラン）に分割する。各ブロックは、挿入ソートを使用して個別にソートされる。
- ソートされたランはマージソートを用いて効率的に統合される。このプロセスでは、サイズが異なる複数のランが選択的にマージされ、最終的に全体がソートされる。

## For each algorithmic approach, apply a prototypical example of the approach
```python
def timsort(arr):
    min_run = 32
    n = len(arr)

    # Create initial runs using insertion sort
    for start in range(0, n, min_run):
        end = min(start + min_run - 1, n - 1)
        for i in range(start + 1, end + 1):
            elem = arr[i]
            j = i - 1
            while j >= start and arr[j] > elem:
                arr[j + 1] = arr[j]
                j -= 1
            arr[j + 1] = elem

    # Merge runs
    size = min_run
    while size < n:
        for left in range(0, n, size * 2):
            mid = min(n - 1, left + size - 1)
            right = min(n - 1, mid + size)
            merge(arr, left, mid, right)
        size *= 2

def merge(arr, left, mid, right):
    merged = []
    i, j = left, mid + 1
    while i <= mid and j <= right:
        if arr[i] <= arr[j]:
            merged.append(arr[i])
            i += 1
        else:
            merged.append(arr[j])
            j += 1
    while i <= mid:
        merged.append(arr[i])
        i += 1
    while j <= right:
        merged.append(arr[j])
        j += 1
    for i, val in enumerate(merged):
        arr[left + i] = val
```

## Given requirements for a problem, develop multiple solutions using various data structures and algorithms. Subsequently, evaluate the suitability, strengths, and weaknesses selecting an approach that best satisfies the requirements.

Timsortは既に部分的にソートされたデータに対して非常に効率的である。小さなランを使用して局所的なソートを行い、それらをマージすることで、少ない比較で全体をソートできる。

## Explain factors beyond computational efficiency that influence the choice of algorithms, such as programming time, maintainability, and the use of application-specific patterns in the input data.

Timsortはその安定性と効率の良さから、PythonやJavaなどの言語の標準ライブラリで採用されている。プログラミングの労力を減らしつつ、複数のデータ型に対応できる汎用性も備えている。

# Timsort vs Merge sort vs Quick sort

### Timsort
- **特性**: 安定なソート。マージソートと挿入ソートの組み合わせ。
- **計算時間**: 最悪の場合でもO(n log n)。
- **メモリ使用**: 追加メモリが必要だが、マージソートより少ない可能性。
- **適切なユースケース**: 部分的にソートされた大規模データ。PythonやJavaで使用。

### Merge Sort
- **特性**: 安定なソート。データを分割してマージ。
- **計算時間**: 常にO(n log n)。
- **メモリ使用**: 全体のデータサイズに等しい追加のメモリが必要。
- **適切なユースケース**: 安定性が重要な大きなデータセット。データベース管理やファイルシステムの最適化に好まれる。

### Quick Sort
- **特性**: 不安定なソート。ピボットを基にデータを分割。
- **計算時間**: 平均と最良はO(n log n)だが、最悪はO(n^2)。
- **メモリ使用**: 再帰の深さによるが追加のメモリは少ない。
- **適切なユースケース**: データの順序がランダムまたは未知の場合に高速。大規模なデータセットでの使用には注意。

#### 影響を与えるその他の要因
- **プログラミングの難易度**: Timsortとマージソートは実装が複雑、クイックソートは比較的容易。
- **保守性**: Timsortは複雑でバグの入り込みやすいが、マージソートやクイックソートは直感的。
- **特定のデータパターンへの適応**: Timsortは既に部分的にソートされたデータに対して顕著な性能を発揮し、他のアルゴリズムより優れる。

# 講義ノート

ピボットの取り方は端っこだけとるとかしない。いい感じにランダムにする

`1,1,1,1,1,1,1`みたいに同じ要素が連なってる時、分割後に入らないようにする
pivot群に入れるようにする

quick sortの長い要素はloop呼び出し、短い方は再帰呼び出しするって方法もある
quick sortは分割の過程で下方向へのアクセス順序なので、同じデータに連続でアクセスしやすい
そのためCPUのキャッシュヒットしやすい

## merge ソート
マージする時は、要素の先頭をだけ見て小さい方を入れつつマージする
O(N logN)

メモリに乗らないデータサイズでも、ファイルの先頭だけを見るのでメモリ使用量を抑えられる可能性が高い


# TimSort
32個くらいのところに境界点がある。
32個以下ならinsert sort使えば良いのではってなってる
キャシュヒット率を考えてマージそ～とできるようになったらマージするようにしている
insertion sortを使う理由

insertion sortはもともとソートされていた場合早い
insertする場合に二分探索が使えるから他のO(N^2)より高速
