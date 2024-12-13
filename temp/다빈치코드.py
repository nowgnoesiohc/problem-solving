import random

card = [0, 0.5, 1, 1.5, 2, 2.5, 3, 3.5, 4, 4.5, 5, 5.5, 6, 6.5, 7, 7.5, 8, 8.5, 9, 9.5, 10, 10.5];
my_card = [1, -1, 8.5, -1]

# def validation(x, rand):
    
    
    


while True:
    rand = random.choice(card)
    
    if (rand*10%10==0):
        print('뽑은 카드는 [검정 %d] 입니다' % (rand))
    else:
        print('뽑은 카드는 [하얀 %d] 입니다' % (rand))
    card.remove(rand)
    # print('확인용 출력', card)
    
    for i in my_card:
        print(' %d' % (i), end='')
    print()
    for i in range(len(my_card)+1):
        print('%d ' % (i), end='')
    print('어느 자리에 넣을지 선택해주세요.')
        
    x = int(input())
    validation(x, rand)
