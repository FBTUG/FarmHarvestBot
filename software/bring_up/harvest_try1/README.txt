
此練習是最小概念性實作一點東西，目的是多了解系統與未來該怎麼設計，基本上就是什麼東西都玩一點的概念
開點 Node, 上 Publisher, Subscriber, Service, Parameters

實作環境
  Eclipse

練習基礎建構在 COSCOP 課程 Code 上
  Harvest Node
   VisionPub
   Task() 
     {
        讀取 Parameters 的設定
        while(){
          Car 往下一位置前進
          持續看收到 Vision 傳來資訊
          發現番茄，Car 停下
          while(){
            要求 VisionService，給個番茄座標
            print("採一個番茄")
          }
        做點 Log
        }
     }
     
  Car Node
    CarService
  Vision Node
    vision_service
    VisionPub


練習步驟
  try coscup_3
  做自己的 Vision Node, make, try
    第一版：第一個自製的 service, 主要是熟悉 build 流程
    Committed revision 3. 
     
  做自己的 Harvest Node  , make, try
  	第二版加入 publisher, subscriber,logger
  完成其他的部分