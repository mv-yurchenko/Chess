########################################################################
########################################################################
# AUTHOR	: Max Yurchenko
# TWITTER	: @mv_yruchenko
# MAIL		:mv.yurchenko.dev@gmail.come
# LICENCE	: GNU GENERAL PUBLIC LICENSE Version 2, June 1991
########################################################################


# Import object classes
from board import *
from engine import *

b=Board()
e=Engine()

while(True):

    b.render()

    c=input('>>> ')

    if c == 'quit' or c == 'exit':
        exit(0)

    elif c == 'undomove':
        e.undomove(b)

    elif 'setboard' in c:
        e.setboard(b,c) 

    elif c == 'getboard':
        e.getboard(b)

    elif c =='go':
        e.search(b)

    elif c=='new' :
        e.newgame(b)

    elif c=='bench' :
        e.bench(b)        

    elif 'sd ' in c :
        e.setDepth(c)

    elif 'perft ' in c:
        e.perft(c,b)        

    elif c=='legalmoves':
        e.legalmoves(b)
        
    else:
        e.usermove(b,c)
