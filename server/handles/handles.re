/**
 * Entry.
 */
let get_handle conn (req: Cohttp.Request.t) body => {
  let handle () => {
    switch (req.resource) {
    | "/" => (Routes.default_route ())
    | _ => (Routes.error_route ())
    }
  };
  handle;
};

let base_handle conn (req: Cohttp.Request.t) body => {
  Lwt_io.printf "Request: %s\n" req.resource; 
  switch (req.meth) {
  | `GET => ((get_handle conn req body) ())
  | _ => (Routes.error_route ())
  }
};
