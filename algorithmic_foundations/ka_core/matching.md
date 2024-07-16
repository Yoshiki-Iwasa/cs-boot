# Efficient string matching

# Boyer-Moore

## Explain a prototypical example of the algorithm
```rust
fn boyer_moore_search(text: &str, pattern: &str) -> Option<usize> {
    let m = pattern.len();
    let n = text.len();
    if m == 0 || n == 0 || m > n {
        return None;
    }

    let mut right = vec![-1; 256];
    for (i, &byte) in pattern.as_bytes().iter().enumerate() {
        right[byte as usize] = i as i32;
    }

    let mut skip;
    for i in 0..=n - m {
        skip = 0;
        for j in (0..m).rev() {
            if pattern.as_bytes()[j] != text.as_bytes()[i + j] {
                skip = j as i32 - right[text.as_bytes()[i + j] as usize];
                if skip < 1 {
                    skip = 1;
                }
                break;
            }
        }
        if skip == 0 {
            return Some(i);
        }
        i += skip as usize;
    }
    None
}
```

## Explain step-by-step how the algorithm operates.
- パターンの各文字について、その文字が最後に出現する位置を記録する。
- テキストを右から左へと比較していき、一致しない場合にスキップする距離を計算する。
- スキップ距離は、不一致が発生した位置と、その文字のパターン内での最後の位置との差に基づいて計算される。
- パターンがテキスト内で見つかればその位置を返し、見つからなければNoneを返す。

## usecase
- テキストエディタやワードプロセッサでの単語検索
- プログラムコード内で特定の文字列パターンを探す開発ツール
- データベース内での文字列検索クエリ
- ウェブページやドキュメント内の特定の情報を抽出するスクリプト

# Longest common subsequence

## Explain a prototypical example of the algorithm

最長共通部分列問題(LCS問題)では、二つのシーケンスが与えられたとき、両方のシーケンスに存在する最も長い部分列を見つけ出すことが目的です。たとえば、シーケンス`"ABCBDAB"`と`"BDCAB"`のLCSは`"BDAB"`です。

## Explain step-by-step how the algorithm operates

1. 二つのシーケンス`X`と`Y`が与えられる。シーケンスの長さをそれぞれ`m`と`n`とする。
2. `LCS`の長さを計算するための二次元配列`C`を作成し、初期化する。配列`C`の各要素`C[i][j]`は、`X`の最初の`i`文字と`Y`の最初の`j`文字から形成されるLCSの長さを表す。
3. 配列を埋めるために、`i`が1から`m`まで、`j`が1から`n`まで繰り返す。各`i`、`j`の位置において、以下のルールに従って`C[i][j]`を計算する:
   - もし`X[i] == Y[j]`ならば、`C[i][j] = C[i-1][j-1] + 1`
   - そうでなければ、`C[i][j] = max(C[i-1][j], C[i][j-1])`
4. `C[m][n]`が`X`と`Y`のLCSの長さを示す。
5. 実際のLCSを取得するために、配列`C`を使って`X`と`Y`を逆にたどる。


```rust
fn lcs(x: &str, y: &str) -> String {
    let mut dp = vec![vec![0; y.len() + 1]; x.len() + 1];

    for (i, xi) in x.chars().enumerate() {
        for (j, yj) in y.chars().enumerate() {
            if xi == yj {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            } else {
                dp[i + 1][j + 1] = dp[i + 1][j].max(dp[i][j + 1]);
            }
        }
    }

    let mut result = String::new();
    let (mut i, mut j) = (x.len(), y.len());
    while i > 0 && j > 0 {
        if x.as_bytes()[i - 1] == y.as_bytes()[j - 1] {
            result.push(x.chars().nth(i - 1).unwrap());
            i -= 1;
            j -= 1;
        } else if dp[i - 1][j] > dp[i][j - 1] {
            i -= 1;
        } else {
            j -= 1;
        }
    }

    result.chars().rev().collect()
}
```

# Regular expression

## Explain a prototypical example of the algorithm

正規表現は、テキスト内でパターンを特定するために使用される文字列のシーケンスです。例えば、`b.` という正規表現は、'b' に続く任意の1文字と一致します。したがって、'b%' や 'bx'、'b5' などがマッチします。このパターンは、具体的な一致から一般的な類似性まで幅広く利用できます。

## Explain step-by-step how the algorithm operates

1. **パターンのコンパイル**: 与えられた正規表現は、内部表現にコンパイルされます。これにより、検索処理が効率的に行われます。
2. **文字列のスキャン**: 正規表現エンジンはテキストを一文字ずつ読み進め、パターンと一致する部分を探します。
3. **マッチの確認**: 各文字がパターンに定義された条件に一致するかどうかをチェックします。例えば、'b.' の場合は、'b' の後に任意の文字が来ることを確認します。
4. **結果の返却**: 一致するすべての部分が見つかると、その情報がユーザーに返されます。一致しない場合は、マッチしないことが報告されます。

```rust
fn main() {
    use regex::Regex;
    let re = Regex::new(r"b.").unwrap();
    let text = "bx by b8 b%";
    for cap in re.captures_iter(text) {
        println!("Matched: {}", &cap[0]);
    }
}
```

# Boyer-Moore
CTRL-Fで見つけるときに使う
