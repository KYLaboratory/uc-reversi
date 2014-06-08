小型マイコン使ってリバーシ
==========

## 概要
- 通常のリバーシは自石で相手石を囲ったとき、ひっくり返す必要がある
- 人手でひっくり返さずとも、自動で白黒が切り替わるリバーシの開発を目的とする

## リバーシのゲーム進行
- 最初に白黒それぞれ2個の石がボードに置いてある
- 白黒交互にボードに石を置いていく
 - 縦・横・斜めで自色で囲った相手色は自色になる
 - 置く場所がなければパスとなる
- ボードが全て埋まったら終了とし、色の多い方の勝ち

## 必要な要素
- 石には白黒の状態がある
 - 石は今自分が何色か知っている
- 隣り合ったマスに石が置かれたとき動作する
 - 相手石で囲まれた場合は色が反転する

## 実現手段

### 色
- 石1つ1つに小型マイコンを載せ制御する
 - マイコンを使ってLEDの色（明暗）を変える
 - マイコンが現在の状態を保持している
 - 石1つ1つには電池が付いており、自力で駆動する

### 色の反転
伝言ゲームの要領で色を伝搬する

1. 石を置く（石をAとする）
1. Aの赤外線LEDが点滅する
 - 色情報と方向（この場合は上）情報を送る
1. 上方向に隣り合った石（Bとする）のフォトトランジスタが受信する
1. 更に上方向に隣り合った石（Cとする）に伝搬する
1. 置いた石と同じ色の石まで伝搬したら折り返す
1. 折り返し信号を受け取った石は色を反転する
1. Aまで信号が戻ってきたら時計方向に次の隣り合った石に信号を送る
 - 伝搬は8方向それぞれで行う
  - BからCに信号を送るとき、方向が不明だと正しく伝搬できないため
 - 折り返さない場合もあるので、一定時間経過したら次の方向に進む
1. 更に隣り合った石に伝搬する
- 石は盤面の情報（どこにどの石があるか）を保持する必要がない

### 石
- 石1つに搭載するもの
 - マイコン
 - LED
 - 赤外線LED
 - フォトトランジスタ x 8

### ボード
- 接触を感知する