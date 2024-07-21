# Turing Machine-based models of complexity

## Explain the Cook-Levin Theorem and the NP-Completeness of SAT.
- Cook-Levinの定理は、最初のNP完全問題としてSAT (充足可能性問題) を証明した定理
- NP完全問題とは、NP (非決定性多項式時間) のクラスに属し、かつ任意のNP問題が多項式時間で帰着できる問題
- この定理により、他の多くのNP問題がNP完全であることを示すための基礎が築かれた

## Explain the classes P and NP.
- Pクラス: 多項式時間で解ける問題のクラス。決定性チューリング機械で解決可能
- NPクラス: 非決定性チューリング機械で多項式時間で検証可能な問題のクラス。解を検証することは容易だが、解を見つけるのは難しい場合がある

## Prove that a problem is NP-Complete by reducing a classic known NP-C problem to it (e.g., 3SAT and Clique).
- 問題がNP完全であることを証明するためには、以下の手順を踏む
  1. 問題がNPに属することを示す
  2. 既知のNP完全問題からその問題に多項式時間で帰着できることを示す
- 例えば、3SAT問題やクリーク問題を使って、新たな問題がNP完全であることを証明できる

## Explain the P-space class and its relation to the EXP class.
- PSpaceクラス: 多項式空間で解決可能な問題のクラス。決定性チューリング機械で使用するメモリが多項式に制限されている
- EXPクラス: 指数時間で解ける問題のクラス。Pよりも広いクラスで、多項式時間では解けないが指数時間で解ける問題が含まれる
- Savitchの定理: NPSpace(非決定性多項式空間) = PSpace。つまり、非決定性チューリング機械で使用する多項式空間は決定性チューリング機械でシミュレートできる
