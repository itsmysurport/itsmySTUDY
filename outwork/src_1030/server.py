from flask import Flask, jsonify
from flask import request

app = Flask(__name__)

@app.route('/', methods = ['POST', 'GET'])
def test():
    a = request.json['username']
    print(a)
    return 'success'

@app.route('/write', methods = ['POST'])
def write():
    title = request.json['title']
    contents = request.json['contents']
    print(title)
    print(contents)
    return 'Hello'
    
if __name__ == '__main__':
    app.run(debug=True)