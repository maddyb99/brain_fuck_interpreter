#INSTALLER FOR LOLCOMPILER
sudo apt-get update -y
sudo apt-get install -y
sudo g++ -o /usr/bin/lol brainfuckinterpreter.cpp
export PATH="$PATH:/usr/bin/lol" >> ~/.bashrc