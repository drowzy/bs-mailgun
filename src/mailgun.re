type t;

module Message = {
  type t = {
    .
    "id": string,
    "message": string
  };
};

module Domain = {
  type t;
};

[@bs.module "mailgun.js"] external make : Js.t({..}) => t = "client";
[@bs.scope "messages"] [@bs.send] external sendMessage : t => string => Js.t({..}) => Js.Promise.t(Message.t) = "create";
[@bs.scope "domains"] [@bs.send] external listDomains : t => unit => Js.Promise.t(array(Domain.t)) = "list";
[@bs.scope "domains"] [@bs.send] external createDomain : t => Js.t({..}) => Js.Promise.t(Domain.t) = "create";
