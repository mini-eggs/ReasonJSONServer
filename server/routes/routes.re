open Cohttp_lwt_unix;

/**
 * Utility function.  
 */
let build_response (status: int) (message: string) => {
  let body = `Assoc [ 
    ("status", `Int status),  
    ("message", `String message)
  ];
  Server.respond_string status::`OK body::(Yojson.Basic.pretty_to_string body);
};

/**
 * Routes.
 */
let default_route () => {
  build_response 1 "Welcome" ();
};

let error_route () => {
  build_response (-1) "Error" ();
};