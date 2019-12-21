int input(char arr[][1000],int cheak[],int n,int computer,int player){
    if(load==1){
        t1 = clock();
    }
    int h,t;
    save_score1[step]=score1;
    save_score2[step]=score2;
    go_equal_arr(arr,n,step);
    go_equal_check(cheak,n,step);
    turns[step]=player;
    ++step;
    op='0';
    int input=0;
    if(computer){
        int u=1;
        while(cheak[u]==1){
            ++u;
        }
        input=u;
    }
    else{
        printf(BLUE "**ENTER THE NUMBER OF THE STICK : " RESET);
        while(1){
            char f[100];
            int d=0;
            int valid=1;
            if(!(load==1&&fscanf(fptr,"%s",&f)==1)){
                load=0;
                gets(&f);
            }
            //printf("%d",strlen(f));
            for(int i=0;i<strlen(f);++i){
                if(isdigit(f[0])!=isdigit(f[i])){
                   valid=0;
                }
            }
            if(isdigit(f[0])==0&&isalpha(f[0])==0){
                valid=0;
            }
            if(valid){
                if(isdigit(f[0])==1){
                    for(int i=0;i<strlen(f);++i){
                    d=d+(f[strlen(f)-1-i]-'0')*pow(10,i);
                    }
                    if(d>0&&d<=n&&cheak[d]==0){
                        input=d;
                        break;
                    }
                }
                else{
                    if(strlen(f)==1){
                        if(f[0]=='u'||f[0]=='U'){
                            op='u';
                            break;
                        }
                        else if(f[0]=='m'||f[0]=='M'){
                            op='m';
                            break;
                        }
                        else if(f[0]=='r'||f[0]=='R'){
                            op='r';
                            break;
                        }
                        else if(f[0]=='s'||f[0]=='S'){
                            op='s';
                            break;
                        }
                        else if(f[0]=='e'||f[0]=='E'){
                            op='e';
                            break;
                        }

                    }
                }
            }
            printf(RED"PLEASE ENTER VALID VALUE : " RESET);
    }

}
if(input!=0){
    if(!computer){
        fprintf(fs,"%d ",input);
    }
    int nn=n+1;
    nn/=2;
    nn=2*nn*(nn-1)+1;
    if(undo){
        if(compu){
            if(computer==1){

            }
            else{
                undo=0;
                for(int i=step;i<nn;++i){
                    turns[i]=0;
                }
            }
        }
        else{
            undo=0;
            for(int i=step;i<nn;++i){
                turns[i]=0;
            }
        }
    }

    int counter=0 ;
    ++cheak[input];
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < n ; j++){
                if(counter<input){
                h=j;
                t=i;
                //break;
            }
            if (arr[j][i]=='0'&&i%2==0&&j%2==0);
            else if (arr[j][i]=='1' && i%2 ==0){ ++counter;}
            else if (arr[j][i]=='1' && i%2 !=0){ ++counter;}
            else if (arr[j][i]=='2' && i%2 ==0){++counter;}
            else if (arr[j][i]=='2' && i%2 !=0) {++counter;}
            else if (arr[j][i]=='A' );
            else if (arr[j][i]=='B' ) ;
            else if (arr[j][i]=='0'&& i%2 !=0&& j%2 !=0&&(i+j)%2==0) ;
            else if (arr[j][i]=='0'&&i%2 !=0) ++counter;
            else if (arr[j][i]=='0'&& i%2 ==0)++counter;

        }
    }

    if(player==1){
        player1 ++ ;
        arr[h][t] = '1';

    }
    else{
        ++player2;
        arr[h][t] = '2';

    }
}
else{
    if(op!='s'&&op!='S')
        fprintf(fs,"%c ",op);
    switch(op){
        case 'm':
            system("1.4.exe");
        break;
        case 'u':
            if(compu){
                if(step>3){
                    for(int f=2;f<step;++f){
                        if(turns[step-f]==2){
                            //turns[step-f]=0;
                            --player2;
                        }
                        else{
                            step=step-f;
                            break;
                        }
                    }
                }
                else{
                    --player2;
                    step=step-4;
                    }
                if(step<0){step=0;}
                arr_equal_go(arr,n,step);
                cheak_equal_go(cheak,n,step);
                --player1;
                if(player2<0){player2=0;}
                if(player1<0){player1=0;}
            }
            else{
                step-=2;
                if(step<0){step=0;}
                arr_equal_go(arr,n,step);
                cheak_equal_go(cheak,n,step);
                if(turns[step]==1){
                    --player1;
                }
                else if (turns[step]==2){
                    --player2;
                }
            }
            score1=save_score1[step];
            score2=save_score2[step];
            turns[0]=1;
            undo=1;
            if(player1<0){player1=0;}
            if(player2<0){player2=0;}
            break;
        case 'r':
            if(compu){
                if(undo&&turns[step]!=0){
                    arr_equal_go(arr,n,step);
                    cheak_equal_go(cheak,n,step);
                    ++player1;

                }
                else{
                    --step;
                }

            }
            else{
                if(undo&&turns[step]!=0){
                    arr_equal_go(arr,n,step);
                    cheak_equal_go(cheak,n,step);
                    if(turns[step-1]==1){
                        ++player1;
                    }
                    else if (turns[step-1]==2){
                        ++player2;
                    }
                }
                else{
                    --step;
                }
            }
            score1=save_score1[step];
            score2=save_score2[step];
            break;

        case's':
            --step;
            fclose(fs);
            char g[1000]="./dotsandboxs/";
            int n=strlen(g);
            for(int i=n; i<strlen(name1)+n; ++i)
                g[i]=name1[i-n];
            n=strlen(g);
            for(int i=n; i<strlen(name2)+n; ++i)
                g[i]=name2[i-n];
            g[strlen(g)]='.';g[strlen(g)]='t';g[strlen(g)]='x';g[strlen(g)]='t';

            char c;
            fs=fopen("./private/test.txt","r");
            fptr2=fopen(g,"w+");
            c = fgetc(fs);
            while (c != EOF)
            {
                fputc(c, fptr2);
                c = fgetc(fs);
            }
            fclose(fptr2);
            fs = fopen("./private/test.txt","a+");
            break;
        case 'e' :
            system("taskkill/IM cb_console_runner.exe");exit(0);
            break;
        default:
            system("taskkill/IM cb_console_runner.exe");exit(0);
            break;
    }
}
}
