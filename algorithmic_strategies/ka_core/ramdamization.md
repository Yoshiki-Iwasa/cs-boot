# Randomized/Stochastic algorithms (e.g., max-cut, balls and bins)

## Explain its definitional characteristics
- ランダム化アルゴリズムは、アルゴリズムの挙動にランダム性を導入し、平均的な性能を向上させたり、最悪のケースの計算時間を改善したりする。
- 出力は、入力だけでなく内部的なランダムな選択にも依存する。
- 決定論的アルゴリズムに比べて、一貫性がないかもしれないが、特定の問題ではより高速またはシンプルな解が得られる場合がある。

## Explain an example that demonstrates the paradigm including how this example satisfies the paradigm’s characteristics
- 例: Max-Cut 問題のランダム化アプローチ
- この問題では、グラフの頂点を二つのグループに分割し、グループ間のエッジの数を最大化する。ランダムに各頂点をどちらかのグループに割り当てることで、期待されるカットサイズは全エッジの約半分になる。この単純なランダム化戦略は、多くの場合で比較的良い近似解を迅速に提供する。

## For each of the algorithms in the AL-Foundational unit, explain the paradigm used by the algorithm and how it exemplifies this paradigm
- **クイックソート**: ピボット選択にランダム性を導入することで平均的な性能が向上する。ランダム化されたピボット選択は、最悪の場合の性能を避け、より一貫した性能を提供する。

## Given an algorithm, explain the paradigm used by the algorithm and how it exemplifies this paradigm
- **ランダム化プリムアルゴリズム**: ランダムにエッジを選択して最小全域木を構築する。これにより、異なる実行で異なる結果が得られるが、平均的には効率的な全域木が得られる。

## Give a real-world problem, evaluate appropriate algorithmic paradigms and algorithms from these paradigms that address the problem including evaluating the tradeoffs among the paradigms and algorithms selected
- 問題: オンライン広告の配置
- アルゴリズム: マルチアームバンディット問題への応用。ランダム化アルゴリズムを使用して、異なる広告戦略の効果を評価し、最適な配置戦略を動的に選択する。
- 評価: ランダム化アルゴリズムは素早い適応が可能だが、最適な選択を保証するものではない。決定論的アルゴリズムよりも不確実性が高いが、大規模なデータセットでは効率的に動作する。
