# HeapSort

## Explain a prototypical example of the algorithm
```rust
fn heapsort(arr: &mut [i32]) {
    build_heap(arr);
    for end in (1..arr.len()).rev() {
        arr.swap(end, 0);
        sift_down(arr, 0, end);
    }
}

fn build_heap(arr: &mut [i32]) {
    let start = (arr.len() - 2) / 2;
    for i in (0..=start).rev() {
        sift_down(arr, i, arr.len());
    }
}

fn sift_down(arr: &mut [i32], start: usize, end: usize) {
    let mut root = start;
    while 2 * root + 1 < end {
        let child = 2 * root + 1;
        let mut swap = root;
        if arr[swap] < arr[child] {
            swap = child;
        }
        if child + 1 < end && arr[swap] < arr[child + 1] {
            swap = child + 1;
        }
        if swap == root {
            break;
        } else {
            arr.swap(root, swap);
            root = swap;
        }
    }
}
```


## Explain step-by-step how the algorithm operates.
- Heapsortは、まず入力配列を二分ヒープに変換する。これにより、配列の最大値が配列の先頭に来る。
- 配列の先頭（最大値）と最後尾を交換し、ヒープのサイズを1減らす。次に、新たな配列先頭をヒープ再構築過程で適切な位置に移動させる。
- ヒープサイズが1になるまでこのプロセスを繰り返す。



# Bucket Sort

## Explain a prototypical example of the algorithm
```rust
fn bucket_sort(arr: &mut [i32], bucket_size: usize) {
    let max = *arr.iter().max().unwrap();
    let min = *arr.iter().min().unwrap();
    let bucket_count = ((max - min) as usize / bucket_size) + 1;
    let mut buckets: Vec<Vec<i32>> = vec![vec![]; bucket_count];

    for &number in arr.iter() {
        let bucket = (number - min) as usize / bucket_size;
        buckets[bucket].push(number);
    }

    for bucket in buckets.iter_mut() {
        bucket.sort();
    }

    let mut idx = 0;
    for bucket in buckets {
        for &number in bucket.iter() {
            arr[idx] = number;
            idx += 1;
        }
    }
}
```

## Explain step-by-step how the algorithm operates.

- 配列をいくつかのバケツに分ける。各要素は、その値に基づいて特定のバケツに配置される。


- 各バケツ内の要素をソートする。通常は別のソートアルゴリズムが使用される。


- ソートされたバケツの内容を元の配列に順に戻して一つのソート済み配列にする。

# Counting Sort

## Explain a prototypical example of the algorithm
```rust
fn counting_sort(arr: &mut [i32], max_value: usize) {
    let mut count = vec![0; max_value + 1];
    for &value in arr.iter() {
        count[value as usize] += 1;
    }

    let mut index = 0;
    for (value, &number) in count.iter().enumerate() {
        for _ in 0..number {
            arr[index] = value as i32;
            index += 1;
        }
    }
}
```

## Explain step-by-step how the algorithm operates.

- 初期化: 入力配列と同じサイズのカウント配列を0で初期化。
- カウント: 各要素の出現回数をカウント配列に記録。
- 累積和: カウント配列を変更して各要素の正確な位置を反映。
- ソート: カウント配列を使って入力配列をソートされた順に再構築。

# Radix Sort

## Explain a prototypical example of the algorithm
```rust
fn radix_sort(arr: &mut [i32]) {
    let max = *arr.iter().max().unwrap();
    let mut exp = 1;
    while max / exp > 0 {
        count_sort(arr, exp);
        exp *= 10;
    }
}

fn count_sort(arr: &mut [i32], exp: i32) {
    let n = arr.len();
    let mut output = vec![0; n];
    let mut count = vec![0; 10];

    for &value in arr.iter() {
        let index = (value / exp) % 10;
        count[index as usize] += 1;
    }

    for i in 1..10 {
        count[i] += count[i - 1];
    }

    for i in (0..n).rev() {
        let value = arr[i];
        let index = (value / exp) % 10;
        output[count[index as usize] as usize - 1] = value;
        count[index as usize] -= 1;
    }

    arr.copy_from_slice(&output);
}
```

## Explain step-by-step how the algorithm operates.
- 配列内の最大値を見つけ、その最大値の桁数を基にループする。
- 各桁に対してカウントソートを行い、それぞれの桁の数に基づいて配列をソートする。
- 最初は一の位に基づいてソートし、次に十の位、百の位と続ける。
- これを最大値の桁数まで繰り返し、最終的に配列が完全にソートされる。
