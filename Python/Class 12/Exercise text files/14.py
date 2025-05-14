def word_count():
    with open('WRITER.txt','r') as f:
        print(len(f.read().split()))
