# Handling exponential growth (heuristic A*, branch-and-bound, backtracking)

## Explain its definitional characteristics
- **Heuristic A***: 問題解決のためにヒューリスティックを用いる探索アルゴリズム。最適な経路を見つけるためにコスト推定値を使用して探索効率を向上させる。
- **Branch-and-bound**: 解の候補を枝分かれさせながら探索し、非効率的な枝を「バウンド」（制限）により剪定して探索空間を縮小する。
- **Backtracking**: 解の候補を逐一構築していき、解が無効であると判断されたら一つ前に戻って他の可能性を探索する。

## Explain an example that demonstrates the paradigm including how this example satisfies the paradigm’s characteristics
- **Example**: ナップザック問題におけるbranch-and-boundアプローチ
- **Explanation**: 各アイテムを含めるかどうかで枝分けを行い、現在のバッグの価値と最大価値の推定を比較して効率的でない枝を剪定する。このプロセスにより、探索空間が効果的に縮小され、計算効率が向上する。

## For each of the algorithms in the AL-Foundational unit, explain the paradigm used by the algorithm and how it exemplifies this paradigm
- **Binary Search**: Decrease-and-conquer。リストを半分に分け、目的の値が中央値より大きいか小さいかで探索範囲を縮小していく。

## Given an algorithm, explain the paradigm used by the algorithm and how it exemplifies this paradigm
- **Dijkstra's Algorithm**: Decrease-and-conquer。最短経路を見つけるために、頂点を一つずつ処理して、残りの頂点の最短距離を更新していく。

## Give a real-world problem, evaluate appropriate algorithmic paradigms and algorithms from these paradigms that address the problem including evaluating the tradeoffs among the paradigms and algorithms selected
- **問題**: 大都市での最適な交通ルートの計算
- **アルゴリズム**: Dijkstraのアルゴリズム（greedyアルゴリズム）、A*アルゴリズム（heuristicアルゴリズム）
- **評価**: Dijkstraのアルゴリズムは正確だが計算量が大きくなる場合がある。A*はヒューリスティックを使うことで効率を向上させるが、ヒューリスティックの質に依存する。
