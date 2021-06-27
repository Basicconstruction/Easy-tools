println("please enter the password for WeChat")
str = "wozhenbang"
while true
    jk = readline()
    if jk == str || jk == "1"
        println("the password is right, we are working on starting the WeChat")
        for i in 1:100
            print(i," ") 
        end
        run(`WeChat`)
    end
end