新的工程
第1方法  ssh     ！！！！ 还需要更正
ssh-keygen -t rsa -C "1328968413@qq.com"
git pull git@github.com:HanKingKong/cpp-docker.git  #现拉取以后的远程库
touch main.cpp
git add main.cpp
git commit -m "first commit"
git push orgin master
git commit -a -m "changed" && git push -u orgin master
git add vimrc
git commit -a -m "changed" && git push -u orgin master


git已有个工程
第2方法 https克隆
git clone https://github.com/HanKingKong/cpp-docker.git
cd cpp-docker
cat vimrc >> ~/.vimrc
vim main.cpp
git config --global user.email "1328968413@qq.com"
git config --global user.name "HanKingKong"
git commit -a -m "change" && git push -u origin master／／需要输入密码

此时，即使有了密钥更新也得输密码，估计是该开始克隆时就设置个方式，可以发现一个文件,库目录/.git/config 
  6 [remote "origin"]
  7     url = https://github.com/HanKingKong/cpp-docker.git
专门查看是用ssh方法的clone的配置文件
        git pull git@github.com:HanKingKong/cpp-docker.git
    [remote "origin"]
	    url = git@github.com:HanKingKong/cpp-docker.git

第3方法 ssh克隆
1. 先创建密钥 
        ssh-keygen -t rsa -C "1328968413@qq.com"
2. 克隆
 cd Code
   48  git clone git@github.com:HanKingKong/cpp-docker.git
   49  cd cpp-docker
   50  ls
3. 设置xxx ???   
	git config --global user.email "1328968413@qq.com"
	git config --global user.name "HanKingKong"
4. 提交更新   
   51  git commit -a -m "change" && git push -u origin master

