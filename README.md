cpp_learning
learn c++
1,ssh-keygen -t rsa -C "shb20170311@163.com"//生成秘钥
2,ssh -T git@github.com //检查是否通讯成功
3，git config --global user.name "shb52dj" //上传的人名字
4，git config --global user.email "shb20170311@163.com" //上传人的邮箱
5, git init //初始化文件夹
6，git add . //提交所有的信息
7,git status //查看所有文件信息
8, git commit -m "my first commit" // 提交到本地库中
9,git remote add origin git@github.com:shb52dj/c-_learning.git //提交到GitHub的仓库中  地址一定是ssh地址
10,git push -u origin master //上传到网络库中
11，git pull --rebase origin master//如果出错，不能上传，就使用这个命令，会把云端的内容复制合并


