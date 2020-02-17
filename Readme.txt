git pull git@github.com:HanKingKong/cpp-docker.git  #现拉取以后的远程库
touch main.cpp
git add main.cpp
git commit -m "first commit"
git push orgin master
git commit -a -m "changed" && git push -u orgin master
git add vimrc
git commit -a -m "changed" && git push -u orgin master


第2方法
git clone https://github.com/HanKingKong/cpp-docker.git
cd cpp-docker
cat vimrc >> ~/.vimrc
vim main.cpp
git config --global user.email "1328968413@qq.com"
git config --global user.name "HanKingKong"
git commit -a -m "change"
git push -u origin master／／需要输入密码
