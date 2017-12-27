# bs-mailgun

BuckleScript bindings for [mailgun.js](https://github.com/mailgun/mailgun-js)

Status: Very basic, need driven.

## Example
```reason
let key = Js.Dict.unsafeGet(Node.Process.process##env, "MAILGUN_API_KEY");
let domain = Js.Dict.unsafeGet(Node.Process.process##env, "MAILGUN_DOMAIN");
let mg = Mailgun.make({"username": "api", "key": key});

let message = {
  "from": "Excited User <mailgun@sandbox-123.mailgun.org>",
  "to": [|"recipient@mail.com"|],
  "subject": "Hello",
  "text": "Testing some Mailgun awesomness!",
  "html": "<h1>Testing some Mailgun awesomness!</h1>"
};

Mailgun.sendMessage(mg, "sandbox-123.mailgun.org", message)
  |> Js.Promise.then_(msg => Js.log(msg) |> Js.Promise.resolve)
  |> Js.Promise.catch(err => Js.log(err) |> Js.Promise.resolve);
```

## Installation

```
npm i --save bs-mailgun
```
Add bs-mailgun to bs-dependencies in your bsconfig.json:

```
{
  ...
  "bs-dependencies": ["bs-mailgun"]
}
```
