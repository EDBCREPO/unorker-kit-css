#pragma once

namespace uk { 

    express_tcp_t overflow() {
        auto app = express::http::add();

        app.ALL([=]( express_http_t cli ){ cli.send();

            for( auto& item : ptr_t<string_t>({
                "hidden", "visible", "scroll", "auto"
            })){
                cli.write( regex::format( _STRING_(
                   .uk-overflow-${0}   { overflow:   ${0}; }
                   .uk-overflow-x-${0} { overflow-x: ${0}; }
                   .uk-overflow-y-${0} { overflow-y: ${0}; }
                ), item ));
            }

        });

        return app;
    }

}